// Problem: D. MEX Tree
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/D
// Memory Limit: 256 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
	统计 mex 信息的一个 trick，统计大于等于 x 的 mex 值的信息，
	做成一个后缀信息，然后单个 mex 值就随便求了
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
const int max_n=2e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int siz[max_n],fa[max_n];
void calsize(int a,int pa)
{
	fa[a]=pa;
	siz[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa){
			calsize(u,a);
			siz[a]+=siz[u];
		}
	}
	return ;
}
ll ans[max_n];
int cnt[max_n];
bool vis[max_n];
int l,r;
int k;
bool find_pa(int a)
{
	int t=a;
	if(!vis[a]){
		while(!vis[fa[a]]){
			a=fa[a];
			vis[a]=true;
			cnt[a]++;
		}
		vis[t]=true;
		cnt[fa[a]]++;
		if(cnt[fa[a]]-(fa[a]==1)>=2) return false;
		if(fa[a]==l) {k=(l==1)?a:k;l=t;}
		else if(fa[a]==r) r=t;
	}
	
	if(r==1){
		ans[t]=1ll*siz[l]*(siz[1]-siz[k]);
	}else{
		ans[t]=1ll*siz[l]*siz[r];
	}
	return true;
}
void solve(int n)
{
	memset(ans,0,sizeof(ll)*(n+3));
	memset(cnt,0,sizeof(int)*(n+3));
	memset(vis,0,sizeof(bool)*(n+3));
	ll sum=0;
	for(int i=head[1];i;i=nxt[i]){
		int &u=to[i];
		ans[0]+=(1ll*siz[u]*(siz[u]-1))/2;
		ans[1]+=siz[u];
		ans[1]+=(sum*siz[u]);
		sum+=siz[u];	
	}
	vis[1]=true;
	l=r=1;
	for(int i=2;i<=n;i++){
		if(!find_pa(i)) break;
	}
	for(int i=1;i<=n;i++){
		ans[i]=ans[i]-ans[i+1];
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		tot=1;
		memset(head,0,sizeof(int)*(n+3));
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			a++,b++;
			add(a,b);
			add(b,a);
		}
		calsize(1,0);
		solve(n);
		for(int i=0;i<=n;i++){
			cout<<ans[i]<<(i==n+1?"":" ");
		}
		cout<<endl;
	}
	return 0;
}