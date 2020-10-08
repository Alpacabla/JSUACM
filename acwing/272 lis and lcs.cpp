/*
link: https://www.acwing.com/problem/content/274/
tags: lis 模板
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
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	vector<vector<int> > dp(n+1,vector<int>(n+1)); 
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(i=1;i<=n;i++){
		cin>>b[i];
	}
	for(i=1;i<=n;i++){
		int max1=0;
		for(j=1;j<=n;j++){
			if(a[i]>b[j]) max1=max(max1,dp[i-1][j]);
			if(a[i]==b[j]) dp[i][j]=max1+1;
			else dp[i][j]=dp[i-1][j];
		}
	}
	int ans=-1;
	for(i=1;i<=n;i++){
		ans=max(dp[n][i],ans);
	}
	cout<<ans<<endl;
	return 0;
}
