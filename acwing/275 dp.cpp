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
int num[55][55];
int dp[55][55];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	n++,m++;
	for(i=2;i<=n;i++){
		for(j=2;j<=m;j++){
			cin>>num[i][j];
		}
	}
	for(i=2;i<=n;i++){
		for(j=2;j<=m;j++){
			int a=dp[i-1][j-1];
			a-=2*num[i-1][j-1];
			int min1=-1;
			min1=max(min1,a+num[i-1][j-1]+num[i][j-1]+num[i-2][j]+num[i-1][j]);
			min1=max(min1,a+num[i-1][j-1]+num[i-1][j]+num[i][j-2]+num[i][j-1]);
			min1=max(min1,a+num[i][j-1]+num[i][j-2]+num[i-1][j]+num[i-2][j]);
			dp[i][j]=min1+2*num[i][j];
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
