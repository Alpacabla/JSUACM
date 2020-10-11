/*
link: https://www.acwing.com/problem/content/description/281/
tags: 完全背包 
feel: 居然没看出来 最后还得看题解 我是脑瘫
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
const ll mod=2147483648;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	vector<ll> dp(n+1);
	dp[0]=1;
	for(i=1;i<n;i++){
		for(j=i;j<=n;j++){
			dp[j]=(dp[j]+dp[j-i])%mod;
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}
