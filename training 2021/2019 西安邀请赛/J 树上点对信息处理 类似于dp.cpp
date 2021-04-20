/*
link: https://nanti.jisuanke.com/t/39277
	  https://blog.csdn.net/qq_38515845/article/details/90582561
tags: 两次dfs统计在同一条链上和不在同一条链上的贡献，很巧妙的思路
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
const int max_n=1e5+5;
int son[max_n<<1],nxt[max_n<<1],head[max_n];
ll ev[max_n<<1];
int n;
inline void add(int a,int b,ll v){
	static int tot=0;
	son[++tot]=b;
	nxt[tot]=head[a];
	ev[tot]=v;
	head[a]=tot;
	return ;
}
int siz[max_n];
ll edot[max_n];
void calsize(int a,int pa,ll vpath)
{
	siz[a]=1;
	edot[a]=vpath;
	for(int i=head[a];i;i=nxt[i]){
		int &u=son[i];
		if(u!=pa){
			calsize(u,a,vpath^ev[i]);
			siz[a]+=siz[u];
		}
	}
	return ;
}
ll ans=0;
const ll mod=1e9+7;
map<ll,ll> mp;
ll sum;
void dfs1(int a,int pa)
{
	ans=(ans+mp[edot[a]]*siz[a])%mod;
	mp[edot[a]]=(mp[edot[a]]+(n-siz[a]+1))%mod;
	for(int i=head[a];i;i=nxt[i]){
		int &u=son[i];
		if(u!=pa){
			mp[edot[a]]=(mp[edot[a]]+(siz[a]-1-siz[u]))%mod;
			dfs1(u,a);
			mp[edot[a]]=(mp[edot[a]]-(siz[a]-1-siz[u])+mod)%mod;
		}
	}
	mp[edot[a]]=(mp[edot[a]]-(n-siz[a]+1)+mod)%mod;
	return ;
}
void dfs2(int a,int pa)
{
	ans=(ans+mp[edot[a]]*siz[a])%mod;
	for(int i=head[a];i;i=nxt[i]){
		int &u=son[i];
		if(u!=pa){
			dfs2(u,a);
		}
	}
	mp[edot[a]]=(mp[edot[a]]+siz[a])%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int fa;
		ll v;
		cin>>fa>>v;
		add(fa,i+1,v);
		add(i+1,fa,v);
	}
	calsize(1,0,0);
	dfs1(1,0);
	mp.clear();
	dfs2(1,0);
	cout<<ans<<endl;
	return 0;
}