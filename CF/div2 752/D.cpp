// Problem: D. Moderate Modular Mode
// Contest: Codeforces - Codeforces Round #752 (Div. 2)
// URL: https://codeforces.com/contest/1604/problem/D
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
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int x,y;
		cin>>x>>y;
		ll ans=0;
		if(x>=y){
			if(x==y) ans=x;
			else ans=1ll*x*y+y;
		}else{
			ll a=x/2,b=y/2;
			ll z=b%a;
			ll v=b/a;
			if(v==1){
				ans=(x+y)/2;
			}else{
				v*=2;
				ans=(v-1)*a+z;
			}
		}
		//cout<<(y%ans==ans%x)<<endl;
		cout<<ans<<endl;
	}
	
	return 0;
}