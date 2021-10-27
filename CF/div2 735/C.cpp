// Problem: C. Mikasa
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/C
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
		ll a,b;
		cin>>a>>b;
		if(a>b) cout<<0<<endl;
		else{
			ll ans=b+a;
			
			while(1){
				int res=-1;
				for(int i=30;i>=0;i--){
					if(ans<(1ll<<i)) continue;
					if(((ans-(1ll<<i))^a)>b){
						res=i;
					}
				}
				if(res==-1){
					break;
				}
				ans-=(1ll<<res);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}