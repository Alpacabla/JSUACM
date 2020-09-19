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
const int max_n=1e4+9;
const int mod=1e4+7;
int dp[2][105][max_n];
int num[105][105];
int main()
{
	int i,j;
	int n,m;
	scanf("%d%d",&n,&m);
	int sum=0;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",num[i]+j);
			num[i][j]%=mod;
		}
	}
	for(i=1;i<=n;i++){
		sum+=num[1][i];
		sum%=mod;
		dp[1][i][sum]=1;
	}
	for(i=2;i<=n;i++){
		int x=i%2;
		int xx=(i-1)%2;
		for(j=1;j<=m;j++){
			for(register int k=0;k<mod;k++){
				dp[x][j][k]=0;
			}
		}
		for(j=1;j<=m;j++){
			for(register int k=0;k<mod;k++){
				if(dp[x][j-1][k]||dp[xx][j][k]){
					dp[x][j][(k+num[i][j])%mod]=1;
				}
			}
		}
	}
	int cnt=0;
	int x=n%2;
	for(i=0;i<mod;i++){
		cnt+=dp[x][m][i];
	}
	printf("%d\n",cnt);
	return 0;
}
