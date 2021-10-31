// Problem: B. Update Files
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
		ll n,k;
		cin>>n>>k;
		ll now=1;
		ll s=1;
		ll cnt=0;
		while(now<n&&s<=k){
			now*=2;
			s*=2;
			cnt++;
		}
		if(now>=n){
			cout<<cnt<<endl;
		}else{
			cout<<cnt+(n-now+k-1)/k<<endl;
		}
	}
	return 0;
}