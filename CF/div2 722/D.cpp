// Problem: D. Kavi on Pairing Duty
// Contest: Codeforces - Codeforces Round #722 (Div. 2)
// URL: https://codeforces.com/contest/1529/problem/D
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
const int max_n=1e6+5;
ll dp[max_n];
const ll mod=998244353 ;
int cnt[max_n];
ll out[max_n];
void init(int n)
{
	dp[1]=1;
	// vector<int> cnt(n+1,1);
	// vector<bool> vis(n+1);
	// for(int i=2;i<=n;i++){
		// if(!vis[i]){
			// for(ll j=1ll*i*2;j<=n;j+=i){
				// cnt[j]++;
				// vis[j]=true;
			// }
			// cnt[i]++;
		// }
	// }
	// for(int i=2;i<=n;i++){
		// for(int j=1;j<i;j++){
			// dp[i]=(dp[i]+dp[j])%mod;
		// }
		// for(int j=1;j<=i;j++){
			// if(i%j==0) dp[i]++;
		// }
		// dp[i]%=mod;
		// //dp[i]=(dp[i]+cnt[i])%mod;
	// }
	
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j+=i){
			cnt[j]++;
		}
	}
	// for(int i=1;i<=15;i++){
		// cout<<cnt[i]<<endl;
	// }
	out[1]=1;
	
	for(int i=1;i<=n;i++){
		out[i]=((out[i-1]*2)%mod+(cnt[i]-cnt[i-1]))%mod;
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	init(1e6);
	cin>>n;
	cout<<out[n]<<endl;
	return 0;
}