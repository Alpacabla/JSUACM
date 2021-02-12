/*
link: https://www.acwing.com/problem/content/description/322/
tags: 简单区间dp 没什么好说的
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
int dp[205][205];
int n;
int a[205];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	cin>>n;
	vector<int> a(2*n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i+n]=a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=2*n-i;j++){
			for(int k=j+1;k<=j+i;k++){
				dp[j][j+i]=max(dp[j][j+i],
					a[j]*a[k]*a[j+i+1]+dp[j][k-1]+dp[k][j+i]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,dp[i][i+n-1]);
	}
	cout<<ans<<endl;
	return 0;
}