// Problem: Collecting Bugs
// Contest: POJ - Northeastern Europe 2004
// URL: http://poj.org/problem?id=2096
// Memory Limit: 64 MB
// Time Limit: 10000 ms
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
double dp[1005][1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,s;
	cin>>n>>s;
	dp[0][0]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=s;j++){
			if(i==0&&j==0) continue;
			//double b=(1-1.0*i/n*j/s);
			double b;
			if(i==n&&j==s){
				b=1;
			}else b=(1-1.0*i/n*j/s);
			dp[i][j]=1/b;
			if(i>=1) dp[i][j]+=dp[i-1][j]*j/s*(n-i+1)/n/b;
			if(j>=1) dp[i][j]+=dp[i][j-1]*i/n*(s-j+1)/s/b;
			if(i>=1&&j>=1) dp[i][j]+=dp[i-1][j]*(s-j+1)/s*(n-i+1)/n/b;
		}
	}
	cout<<dp[n][s]<<endl;
	return 0;
}