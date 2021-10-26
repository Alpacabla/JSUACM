// Problem: E. Pchelyonok and Segments
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/E
// Memory Limit: 512 MB
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
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		vector<ll> sum(n+1);
		for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
		vector<vector<ll>> dp(n+2,vector<ll> (455));
		dp[n+1][0]=ll_inf;
		for(int i=n+1;i>=1;i--){
			for(int j=1;j<=450;j++){
				if(dp[i][j-1]==0) break;
				if(i-j-1<0) break;
				if(dp[i][j-1]>(sum[i-1]-sum[i-j-1])){
					dp[i-j][j]=max(dp[i-j][j],sum[i-1]-sum[i-j-1]);
				}
			}
			for(int j=0;j<=450;j++){
				dp[i-1][j]=max(dp[i][j],dp[i-1][j]);
			}
		}
		int ans=0;
		for(int i=1;i<=450;i++){
			if(dp[1][i]!=0) ans=i;
		}
		cout<<ans<<endl;
	}
	return 0;
}