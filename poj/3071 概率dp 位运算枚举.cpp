/*
link: 
tags: 
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#pragma GCC optimize(2)
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=(1<<7);
double a[max_n][max_n];
double dp[8][max_n];
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int n;
	while(scanf("%d",&n)&&(~n)){
		//vector<vector<double> > a((1<<n),vector<double>((1<<n)));
 		for(int i=0;i<(1<<n);i++){
 			for(int j=0;j<(1<<n);j++){
 				scanf("%lf",&a[i][j]);
 			}
 		}
 		//vector<vector<double> > dp(n+1,vector<double>((1<<n)));
 		for(int i=0;i<(1<<n);i++){
 			dp[0][i]=1.0;
 		}
 		for(int i=1;i<=n;i++){
	 		for(int j=0;j<(1<<n);j++){
	 			dp[i][j]=0;
	 		}	
 		}
 		for(int i=1;i<=n;i++){
 			for(int j=0;j<(1<<(i-1));j++){
 				for(int k=j;k<(1<<n);k+=(1<<i)){
 					for(int l=0;l<(1<<(i-1));l++){
 						int y=k-j+(1<<(i-1))+l;
 						dp[i][k]+=dp[i-1][y]*dp[i-1][k]*a[k][y];
 						dp[i][y]+=dp[i-1][y]*dp[i-1][k]*a[y][k];	
 					}
 				}
 			}
 		}
 		double max1=-1;
 		int ans=0;
 		for(int i=0;i<(1<<n);i++){
 			if(dp[n][i]>max1){
 				max1=dp[n][i];
 				ans=i+1;
 			}
 		}
 		printf("%d\n",ans);
	}
	return 0;
}