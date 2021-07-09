// Problem: C. Strange Function
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//不错的容斥题

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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ll ans=0;
		ll x=1;
		for(int i=2;i<=100;i++){
			ll cnt=(n-n/i)%mod;
			cnt=(cnt-(n-n/x-n/i+(n/(x*i/__gcd(x,i*1ll))))%mod)%mod;
			cnt=(cnt+mod)%mod;
			x=x/__gcd(x,i*1ll)*i;
			ans=(ans+i*cnt%mod)%mod;
			if(x>n) {break;}
		}
		cout<<ans<<endl;
	}
	return 0;
}