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
const int max_n=1e4+5;
const int mod=9999973;
ll dp[105][105][105];
inline ll C(ll a){
	return (a*(a-1))/2;
}
void shift(int n,ll a,ll b,const ll m)
{
	//a a个放了1个棋的列 b 0 c 2    一行一次只能放0-2个
	ll c=m-a-b;
	dp[n][a][b]=(dp[n][a][b]+dp[n-1][a][b])%mod;//不放
	if(a>=1) dp[n][a][b]=(dp[n][a][b]+dp[n-1][a-1][(b+1)]*(b+1))%mod;//放一个放在0的列
	//if(b<m) dp[n][a][b]=(dp[n][a][b]+dp[n-1][a][b+1]*(b+1))%mod;//放两个放在0的列
	if(a+1<=m) dp[n][a][b]=(dp[n][a][b]+dp[n-1][a+1][b]*(a+1))%mod;//放一个放在1的列
	if(a>=2) dp[n][a][b]=(dp[n][a][b]+dp[n-1][a-2][b+2]*C(b+2))%mod;//放两个在两个0列里
	if(a+2<=m) dp[n][a][b]=(dp[n][a][b]+dp[n-1][a+2][b]*C(a+2))%mod;//放两个在1列里
	if(c+1<=m&&b+1<=m) dp[n][a][b]=(dp[n][a][b]+dp[n-1][a][b+1]*(a)*(b+1))%mod;//放一个在1列，一个在0列
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k;
	int n,m;
	cin>>n>>m;
	dp[0][0][m]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=m;j++){
			for(k=0;k<=m-j;k++){
				shift(i,1ll*j,1ll*k,1ll*m);
			}
		}
	}
	int ans=0;
	for(i=0;i<=m;i++){
		for(j=0;j<=m-i;j++){
			ans=(ans+dp[n][i][j])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
