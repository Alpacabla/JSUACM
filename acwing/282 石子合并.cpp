/*
link: https://www.acwing.com/problem/content/submission/284/
tags: 区间dp
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
int dp[305][305];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	vector<int> num(n+1),sum(n+1);
	for(i=1;i<=n;i++){
		cin>>num[i];
		sum[i]=sum[i-1]+num[i];
	}
	for(i=1;i<=n;i++){
		for(j=1;j+i<=n;j++){
			int res=int_inf;
			for(int k=j;k<j+i;k++){
				res=min(res,dp[j][k]+dp[k+1][j+i]+sum[j+i]-sum[j-1]);
			}
			dp[j][j+i]=res;
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
