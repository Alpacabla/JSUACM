// Problem: B. AND 0, Sum Big
// Contest: Codeforces - Codeforces Round #716 (Div. 2)
// URL: https://codeforces.com/contest/1514/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll res=1;
		while(k){
			if(k&1){
				res=res*n%mod;
			}
			n=n*n%mod;
			k>>=1;
		}
		cout<<res<<endl;
	}
	return 0;
}