#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
//#define endl '\n'
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e6+5;
const ll mod=1e9+7;
ll inv[max_n*2];
int pos[(1<<14)+1];
void init(int n)
{
	inv[1]=1;
	for(int i=2;i<=n;i++){
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=0;i<14;i++){
		pos[(1<<i)]=i;
	}
	return ;
}
ll g[15][(1<<14)];
ll f[(1<<14)],p[(1<<14)];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	init(2e6);
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		g[i][0]=1;
		for(int j=1;j<(1<<n);j++){
			
			g[i][j]=g[i][j-lowbit(j)]*inv[a[pos[lowbit(j)]]+a[i]]%mod*a[i]%mod;
		}
	}
	const int lim=(1<<n)-1;
	ll ans=0;
	for(int i=1;i<(1<<n);i++){
		p[i]=1;
		for(int j=i;j>0;j=i&(j-lowbit(i))){
			if(j==i) continue;
			ll x=1;
			for(int k=j;k>0;k-=lowbit(k)){
				x=x*g[pos[lowbit(k)]][i^j]%mod;
			}
			p[i]=(p[i]-p[j]*x%mod)%mod;
		}
		ll x=1;
		for(int j=i;j>0;j-=lowbit(j)){
			x=x*g[pos[lowbit(j)]][lim^i]%mod;
		}
		f[i]=p[i]*x%mod;
		ans=(ans+f[i]*__builtin_popcount(i))%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}