// Problem: D. Ezzat and Grid
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e7+5;
int tot=1;
int max1[max_n],lson[max_n],rson[max_n],tag[max_n],max2[max_n],tagg[max_n];
void maintain(int a)
{
	if(max1[lson[a]]>max1[rson[a]]){
		max1[a]=max1[lson[a]];
		tag[a]=tag[lson[a]];
	}else{
		max1[a]=max1[rson[a]];
		tag[a]=tag[rson[a]];
	}
} 
int insert(int ind,int l1,int r1,int l2,int r2,int val,int iii)
{
	int now=ind;
	if(l1>r2||r1<l2){
		return now;
	}
	if(!now){
		now=++tot;
	}
	if(l1>=l2&&r1<=r2){
		if(max2[now]<val){
			tagg[now]=iii;
			max2[now]=val;
		}
		if(max1[now]<val){
			max1[now]=val;
			tag[now]=iii;
		}
		return now;
	}
	int mid=(l1+r1)>>1;
	lson[now]=insert(lson[now],l1,mid,l2,r2,val,iii);
	rson[now]=insert(rson[now],mid+1,r1,l2,r2,val,iii);
	maintain(now);
	return now;
}
int vvv;
void check(int ind,int l1,int r1,int l2,int r2,int &val)
{
	if(!ind||l1>r2||r1<l2){
		return ;
	}
	if(max2[ind]>val) val=max2[ind],vvv=tagg[ind];
	if(l1>=l2&&r1<=r2){
		if(max1[ind]>val) val=max1[ind],vvv=tag[ind];
		return ;
	}
	int mid=(l1+r1)>>1;
	check(lson[ind],l1,mid,l2,r2,val);
	check(rson[ind],mid+1,r1,l2,r2,val);
	//return val;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<vector<pair<int,int> > > s(n+1,vector<pair<int,int>>(0));
	while(m--){
		int a,l,r;
		cin>>a>>l>>r;
		s[a].push_back(make_pair(l,r));
	}
	vector<int> last(n+1);
	int ans=-1,end;
	for(int i=1;i<=n;i++){
		int res=0;
		vvv=0;
		for(int j=0;j<s[i].size();j++){
			check(1,1,1e9,s[i][j].first,s[i][j].second,res);
		}
		for(int j=0;j<s[i].size();j++){
			insert(1,1,1e9,s[i][j].first,s[i][j].second,res+1,i);
		}
		last[i]=vvv;
		if(res>ans){
			ans=res,end=i;
		}
	}
	vector<bool> vis(n+1);
	while(end!=0){
		vis[end]=true;
		end=last[end];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cnt+=vis[i];
	}
	cout<<n-cnt<<endl;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cout<<i<<" ";
		}
	}
	cout<<endl;
	return 0;
}