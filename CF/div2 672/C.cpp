/*
link: 
tags: 
*/
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
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<ll> num(n+1),dp[2];
		dp[0].resize(n+1);
		dp[1].resize(n+1);
		for(i=1;i<=n;i++){
			cin>>num[i];
			//dp[0][i]=dp[1][i]=0;
		}
		for(i=1;i<=n;i++){
			dp[0][i]=max(dp[1][i-1]-num[i],dp[0][i-1]);
			dp[1][i]=max(dp[0][i-1]+num[i],dp[1][i-1]);
		}
		cout<<max(dp[0][n],dp[1][n])<<endl;
	}
	return 0;
}
