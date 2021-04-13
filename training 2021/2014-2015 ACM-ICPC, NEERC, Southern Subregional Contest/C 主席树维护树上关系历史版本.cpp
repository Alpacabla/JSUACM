/*
link: https://codeforces.com/gym/100513/problem/C
tags: 用主席树维护树上到根路径的历史版本的板子
	  唯一要注意的是某节点是空节点时要特判
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=3e5+5;
int head[max_n],son[max_n],nxt[max_n],tottot;
inline void add(int a,int b){
	son[++tottot]=b;
	nxt[tottot]=head[a];
	head[a]=tottot;
	return ;
}
const int lim=3e5;
vector<string> s[max_n],vals[max_n];
map<string,int> mp;
int pa[max_n];
int tree[max_n],lson[max_n*20],rson[max_n*20],tot;
string sss[max_n*20];
int add_link(int last,int ind,int l=1,int r=lim)
{
	if(!last) return ind;
	if(!ind) return last;
	if(l==r) return ind;
	int mid=(l+r)>>1;
	lson[ind]=add_link(lson[last],lson[ind],l,mid);
	rson[ind]=add_link(rson[last],rson[ind],mid+1,r);
	return ind;
}
int creat_link(int ind,int v,string &ss,int l=1,int r=lim)
{
	int now=ind;
	if(!now) now=++tot;
	if(l==r){
		sss[now]=ss;
		return now;
	}
	int mid=(l+r)>>1;
	if(v<=mid){
		lson[now]=creat_link(lson[now],v,ss,l,mid);
	}else{
		rson[now]=creat_link(rson[now],v,ss,mid+1,r);
	}
	return now;
}
void init()
{
	stack<int> sta;
	sta.push(1);
	static int all=0;
	int last=0;
	while(sta.size()){
		int k=sta.top();
		sta.pop();
		for(int i=1;i<s[k].size();i++){
			int val;
			auto it=mp.find(s[k][i]);
			if(it==mp.end()) val=mp[s[k][i]]=++all;
			else val=(it->second);
			tree[k]=creat_link(tree[k],val,vals[k][i]);
		}
		tree[k]=add_link(tree[pa[k]],tree[k]);
		for(int i=head[k];i;i=nxt[i]){
			sta.push(son[i]);
		}
	}
	return ;
}
string NA="N/A";
string& find(int ind,int val,int l=1,int r=lim)
{
	if(!ind) return NA;
	if(l==r) return sss[ind];
	int mid=(l+r)>>1;
	if(val<=mid) return find(lson[ind],val,l,mid);
	else return find(rson[ind],val,mid+1,r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
 
	for(int i=1;i<=n;i++){
		int m;
		cin>>pa[i]>>m;
		if(pa[i]!=0) add(pa[i],i);
		s[i].resize(m+1);
		vals[i].resize(m+1);
		for(int j=1;j<=m;j++){
			string temp;
			cin>>temp;
			int pos=temp.find('=');
			s[i][j]=temp.substr(0,pos);
			vals[i][j]=temp.substr(pos+1);
		}
	}
	init();
 
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int k;
		string str;
		cin>>k>>str;
		int z=mp[str];
		if(!z) cout<<"N/A"<<endl;
		else cout<<find(tree[k],mp[str])<<endl;
		fflush(stdout);
	}
	return 0;
}