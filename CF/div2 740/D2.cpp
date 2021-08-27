// Problem: D2. Up the Strip
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/D2
// Memory Limit: 128 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
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
	int n,m;
	cin>>n>>m;
	const int mod=m;
	vector<int> dp(n+1),sum(n+1),vv(n+1);
	
	sum[1]=dp[1]=1;
	
	for(int i=2;i<=n;i++){
		vv[i]=(vv[i]+vv[i-1]+1)%mod;
		dp[i]=((dp[i]+sum[i-1])%mod+vv[i])%mod;
		for(int j=2;j*i<=n;j++){
			vv[j*i]=(vv[j*i]+(dp[i]-dp[i-1])%mod)%mod;
		}
		sum[i]=(sum[i-1]+dp[i])%mod;
	}
	cout<<(dp[n]+mod)%mod<<endl;
	return 0;
}