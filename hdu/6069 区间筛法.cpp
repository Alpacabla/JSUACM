/*
link: 
tags: 
*/
#include<set>
#include<iostream>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e6+5;
int pri[max_n],tot;
bool notpri[max_n];
inline void init(const int n)
{
	notpri[2]=false;
	for(int i=2;i<=n;i++){
		if(!notpri[i]){
			pri[tot++]=i;
			for(ll j=1ll*i*i;j<=n;j+=i){
				notpri[j]=true;
			}
		}
	}
	return ;
}
const int mod=998244353;
ll aa[max_n];
ll res[max_n];
int solve(ll l,ll r,ll kk)
{
	ll z=0;
	for(int i=0;i<tot;i++){
		for(ll j=((l+pri[i]-1)/pri[i])*pri[i];j<=r;j+=pri[i]){
			int cnt=0;
			ll x=1;
			while(aa[j-l]%pri[i]==0){
				aa[j-l]/=pri[i];
				cnt++;
			}
			x=(x*((cnt*kk)%mod+1))%mod;
			res[j-l]=(res[j-l]*x)%mod;
		}
	}
	ll ans=0;
	for(ll j=0;j+l<=r;j++){
		if(aa[j]!=1){
			res[j]=(res[j]*(kk+1))%mod;
		}
		ans=(ans+res[j])%mod;
	}
	return ans;
}
/*
5
900000000000 900001000000 5
*/
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(1e6);
	int t;
	cin>>t;
	while(t--){
		ll l,r,k;
		cin>>l>>r>>k;
		for(ll i=0;i+l<=r;i++){
			aa[i]=l+i;
			res[i]=1;
		}
		cout<<solve(l,r,k)<<endl;

	}
	return 0;
}