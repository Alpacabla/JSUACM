// Problem: B. Odd Grasshopper
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/B
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
		ll a,n;
		cin>>a>>n;
		//if(a%2==0){
			ll v=n/4;
			for(ll i=v*4+1;i<=n;i++){
				if(a%2==0) a-=i;
				else a+=i;
			}
			cout<<a<<endl;
		// }else{
// 			
		// }
	}
	return 0;
}