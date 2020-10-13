/*
link: https://www.acwing.com/problem/content/description/277/
tags: dp dp dp 为什么就学不会呢
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
int dp[105][55][55];
int num[55][55];
inline int val(int a,int b,const int k)
{
	return num[a][k-a+2]+num[b][k-b+2];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k;
	int n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>num[i][j];
		}
	}
	int lim=n+m-2;
	for(k=1;k<=lim;k++){
		for(i=max(1,k+2-m);i<=n&&i<=k+2;i++){
			for(j=max(1,k+2-m);j<=n&&j<=k+2;j++){
				if(i!=j||k==lim){
					int max1=-1;
					max1=max(max1,dp[k-1][i][j]+val(i,j,k));
					max1=max(max1,dp[k-1][i-1][j-1]+val(i-1,j-1,k));
					if(i-1!=j) max1=max(max1,dp[k-1][i-1][j]+val(i-1,j,k));
					if(i!=j-1) max1=max(max1,dp[k-1][i][j-1]+val(i,j-1,k));
					dp[k][i][j]=max1;
				}
			}
		}
	}
	cout<<dp[lim][n][n]<<endl;
	return 0;
}
