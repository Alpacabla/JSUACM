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
int dp[55][55][55][55];
int num[55][55];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k,l;
	int n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>num[i][j];
		}
	}
	memset(dp,0x3f3f,sizeof(dp));
	dp[1][1][1][1]=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			for(k=1;k<=i;k++){
				for(l=m;l>=j;l--){
					
				}
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
