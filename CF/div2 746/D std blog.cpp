// Problem: D. Hemose in ICPC ?
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e3+5;
int query(vector<int> a){
	cout<<"? "<<a.size();
	for(int i=0;i<a.size();i++){
		cout<<" "<<a[i];
	}
	cout<<endl;
	cout.flush();
	int res;
	cin>>res;
	return res;
}
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot=1;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int eudfn[max_n<<1];
int times;
void dfs(int a,int pa)
{
	eudfn[++times]=a;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa){
			dfs(u,a);
			eudfn[++times]=a;
		}
	}
	return ;
}
bool vis[max_n];
int judge(int l,int r)
{
	vector<int> q;
	for(int i=l;i<=r;i++){
		if(!vis[eudfn[i]]){
			vis[eudfn[i]]=true;
			q.push_back(eudfn[i]);
		}
	}
	for(int i=0;i<q.size();i++) vis[q[i]]=false;
	return query(q);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	dfs(1,-1);
	vector<int> q(n);
	for(int i=0;i<n;i++){
		q[i]=i+1;
	}
	int vv=query(q);
	int l=1,r=2*n;
	int res1,res2;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(judge(l,mid)==vv){
			r=mid;
			res1=eudfn[l];
			res2=eudfn[mid];
		}else{
			res1=eudfn[mid];
			res2=eudfn[r];
			l=mid;
		}
	}
	cout<<"! "<<res1<<" "<<res2<<endl;
	return 0;
}