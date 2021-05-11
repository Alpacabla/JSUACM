// Problem: C. Problem for Nazar
// Contest: Codeforces - Codeforces Round #553 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1151/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int max_n=1e5+5;
const ll mod=1e9+7;
ll inv2;
void init()
{
	ll a=2;
	ll res=1;
	int b=mod-2;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	inv2=res;
	return ;
}
ll solve(ll a)
{
	ll now=0;
	ll add=0;
	ll cnt1=0,cnt2=0;
	while((now+(1ll<<add))<=a){
		now+=(1ll<<add);
		if(add%2ll==0){
			cnt1+=(1ll<<add);
		}else{
			cnt2+=(1ll<<add);
		}
		add++;
	}
	if(now!=a){
		if(add%2ll==0){
			cnt1+=a-now;
		}else{
			cnt2+=a-now;
		}
	}
	cnt1%=mod;
	cnt2%=mod;
	return (((1ll+(cnt1-1ll)*2ll+1ll)%mod*cnt1%mod)*inv2%mod+((2ll+(cnt2)*2ll)%mod*cnt2%mod)*inv2%mod)%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	ull l,r;
	cin>>l>>r;
	cout<<(solve(r)-solve(l-1)+mod)%mod<<endl;
	return 0;
}