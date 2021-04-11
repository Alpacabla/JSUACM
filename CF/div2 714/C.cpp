// Problem: C. Add One
// Contest: Codeforces - Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
// URL: https://codeforces.com/contest/1513/problem/C
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
const int max_n=2e5+15;
const int mod=1e9+7;
int dp[max_n][10];
void init(const int n)
{
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<10;j++){
			dp[i][j]=dp[i-1][j-1];  
		}
		dp[i][0]=dp[i-1][9];
		dp[i][1]=(dp[i][1]+dp[i-1][9])%mod;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(2e5+10);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int num,m;
		cin>>num>>m;
		int ans=0;
		while(num){
			int k=num%10;
			num/=10;
			for(int j=0;j<=9;j++){
				ans=(ans+dp[m+k][j])%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}