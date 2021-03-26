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
	ll n;
	ll dp[105];
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<100;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	cin>>n;
	cout<<(int)(upper_bound(dp,dp+92,n)-dp)<<endl;
	return 0;
}