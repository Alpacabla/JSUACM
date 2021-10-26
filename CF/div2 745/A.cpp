// Problem: A. CQXYM Count Permutations
// Contest: Codeforces - Codeforces Round #745 (Div. 2)
// URL: https://codeforces.com/contest/1581/problem/A
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
		int n;
		cin>>n;
		const int mod=1e9+7;
		int ans=1;
		for(int i=3;i<=2*n;i++){
			ans=1ll*ans*i%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}