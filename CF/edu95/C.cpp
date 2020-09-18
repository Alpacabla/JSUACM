/*
link: https://codeforces.com/contest/1418/problem/C
tags: dp
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
const int max_n=2e5+5;
int dp[max_n][2];
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>num[i];
		}
		if(n==1){
			cout<<(num[1]==1)<<endl;
			continue;
		}
		dp[1][0]=(num[1]==1);
		dp[2][0]=dp[1][0]+(num[2]==1);
		dp[1][1]=int_inf;
		dp[2][1]=dp[1][0];
		for(i=3;i<=n;i++){
			dp[i][0]=min(dp[i-1][1]+(num[i]==1),dp[i-2][1]+(num[i]==1)+(num[i-1]==1));
			dp[i][1]=min(dp[i-1][0],dp[i-2][0]);
		}
		cout<<min(dp[n][0],dp[n][1])<<endl;
	}
	return 0;
}
