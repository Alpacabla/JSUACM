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
	int n,k;
	cin>>n>>k;
	vector<int> h(n+1),dp(n+1);
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=2;i<=n;i++){
		dp[i]=int_inf;
		for(int j=1;i-j>=1&&j<=k;j++){
			dp[i]=min(dp[i],abs(h[i]-h[i-j])+dp[i-j]);
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}