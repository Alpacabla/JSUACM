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
const ll mod=998244353;
ll qpow(ll a,int b)
{
	ll res=1;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int to[max_n<<1],nxt[max_n<<1],head[max_n];
ll ev[max_n<<1];
inline void add(int a,int b,ll v){
	static int tot=0;
	to[++tot]=b;
	nxt[tot]=head[a];
	ev[tot]=v;
	head[a]=tot;
	return ;
}
bool vis[max_n];
int siz[max_n];
void calsize(int a,int pa)
{
	siz[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=pa){
			calsize(u,a);
			siz[a]+=siz[u];
		}
	}
	return ;
}
int cen;
int all;
int min1;
void calcen(int a,int pa)
{
	//static int min1=int_inf;
	int max1=all-siz[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
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
ll ans=0;
int k;
ll sum[20];
ll C[20];
void caladd(int a,int pa,ll len)
{
	len%=mod;
	ll res=0;
	ll x=1;
	for(int i=0;i<=k;i++){
		res=res+C[i]*x%mod*sum[k-i]%mod;
		res%=mod;
		x=x*len%mod;
	}
	ans=(ans+res)%mod;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=pa){
			caladd(u,a,len+ev[i]);
		}
	}
	return ;
}
void addlink(int a,int pa,ll len)
{
	len%=mod;
	ll x=1;
	for(int i=0;i<=k;i++){
		sum[i]=(sum[i]+x)%mod;
		x=x*len%mod;
	}
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=pa){
			addlink(u,a,len+ev[i]);
		}
	}
	return ;
}
void calans(int a)
{
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			caladd(u,a,ev[i]);
			addlink(u,a,ev[i]);
		}
	}
	ans=(ans+sum[k])%mod;
	for(int i=0;i<=15;i++){
		sum[i]=0;
	}
}
void dfz(int a)
{
	min1=int_inf;
	calsize(a,0);
	all=siz[a];
	cen=a;
	calcen(a,0);
	calsize(cen,0);
	calans(cen);
	vis[cen]=true;
	for(int i=head[cen];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			dfz(u);
		}
	}
}
ll X[20],xx[20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n>>k;
	X[0]=1;
	xx[0]=qpow(1,mod-2);
	for(int i=1;i<=k;i++){
		X[i]=X[i-1]*i%mod;
		xx[i]=qpow(X[i],mod-2);
	}
	for(int i=0;i<=k;i++){
		C[i]=X[k]*xx[i]%mod*xx[k-i]%mod;
	}
	for(int i=2;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	dfz(1);
	cout<<2*ans%mod*qpow(1ll*n*n%mod,mod-2)%mod<<endl;
	return 0;
}