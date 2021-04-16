/*
link: 
tags: 
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
inline void add(int a,int b,ll v){
	static int tot=0;
	son[++tot]=b;
	nxt[tot]=head[a];
	ev[tot]=v;
	head[a]=tot;
	return ;
}
int trsiz[max_n];
int fa[max_n];
void caltrsize(int a,int pa)
{
	fa[a]=pa;
	trsiz[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=son[i];
		if(!vis[u]&&u!=pa){
			caltrsize(u,a);
			trsiz[a]+=trsiz[u];
		}
	}
	return ;
}
bool vis[max_n];
int siz[max_n];
int kk;
int all;
void calsize(int a,int pa)
{
	siz[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=son[i];
		if(!vis[u]&&u!=pa){
			calsize(u,a);
			siz[a]+=siz[u];
		}
	}
	return ;
}
int cen;
void calcen(int a,int pa)
{
	static int min1=int_inf;
	int max1=all-siz[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=son[i];
		if(!vis[u]&&u!=pa){
			calcen(u,a);
			max1=max(max1,siz[u]);
		}
	}
	if(max1<min1){
		min1=max1;
		cen=a;
	}
	return ;
}
map<ll,ll> mp;
const ll mod=1e9+7;
ll ans;
void caladd(int a,int pa,ll pv)
{
	ans+=mp[pv]*(pa==fa[a]?trsiz[a]:kk-trsiz[pa])%mod;
	for(int i=head[a];i;i=nxt[i]){
		int &u=son[i];
		if(!vis[u]&&u!=pa){
			caladd(u,a,pv^ev[i]);
		}
	}
	return ;
}
void calpath(int a,int pa,ll pv)
{
	mp[pv]+=(pa==fa[a]?trsiz[a]:kk-trsiz[pa]);
	for(int i=head[a];i;i=nxt[i]){
		int &u=son[i];
		if(!vis[u]&&u!=pa){
			calpath(u,a,pv^ev[i]);
		}
	}
	return ;
}
void calans(int a)
{
	ll tsiz=0;
	for(int i=head[a];i;i=nxt[i]){
		int &u=son[i];
		if(!vis[u]){
			tsiz=mp[0];
			caladd(u,a,ev[i]);
			calpath(u,a,ev[i]);
			ans=(ans+(siz[a]-siz[u])*(mp[0]-tsiz)%mod)%mod;
		}
	}
	mp.clear();
	return ;
}
void dfz(int a)
{
	calsize(a,0);
	all=siz[a];
	calcen(a,0);
	calsize(cen,0);
	cout<<"censiz";
	cout<<cen<<endl;
	//cout<<siz[cen]<<endl;
	calans(cen);
	cout<<ans<<endl;
	vis[cen]=true;
	for(int i=head[cen];i;i=nxt[i]){
		int &u=son[i];
		if(!vis[u]){
			dfz(u);
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	kk=n;
	for(int i=1;i<n;i++){
		int fa;
		ll v;
		cin>>fa>>v;
		add(fa,i+1,v);
		add(i+1,fa,v);
	}
	dfz(1);
	cout<<ans<<endl;
	return 0;
}