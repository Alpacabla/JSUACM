// Problem: A. Contest Start
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.com/contest/1539/problem/A
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll a,b,c;
		cin>>a>>b>>c;
		
		ll t=c/b;
		t++;
		ll k=a%(t+1);
		if(a<t){
			cout<<(0+a-1)*(a)/2<<endl;
			continue;
		}
		
		ll ans=a*(t-1)-(0+t-1)*(t)/2;
		
		cout<<ans<<endl;
	}
	return 0;
}