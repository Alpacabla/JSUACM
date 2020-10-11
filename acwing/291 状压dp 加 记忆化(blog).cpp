/*
link: https://www.acwing.com/problem/content/293/
tags: dp 记忆化
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
ll dp[12][(1<<11)+10];
ll ans[12][12];
bool able[12][(1<<11)+10];
void init_dp(int m)
{
	int n=11;
	int lim=(1<<m)-1;
	int i,j,k;
	dp[0][lim]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=lim;j++){
			dp[i][j]=0;
			for(k=0;k<=lim;k++){
				if(!(k&j)&&(able[m][k|j])){
					dp[i][j]+=dp[i-1][k];
				}
			}
		}
	}
	dp[0][lim]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<=lim;j++){
			if(able[m][j]) ans[i][m]+=dp[i][j];
		}
	}
	return ;
}
bool judge(int a,const int m)
{
	a+=(1<<m);
	for(int i=0;i<m;i++){
		if(((a&1)==0)&&((a&2)==0)){
			i++;
			a>>=2;
			continue;
		}
		if((a&1)==0&&(a&2)==2){
			return false;
		}
		a>>=1;
	}
	return true;
}
void init()
{
	const int lim=(1<<11)-1;
	for(int k=1;k<=11;k++){
		for(int i=0;i<=lim;i++){
			able[k][i]=judge(i,k);
		}
	}
	for(int i=1;i<=11;i++){
		init_dp(i);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k;
	int n,m;
	
	init();
	
	while(cin>>n>>m){
		if(n==0||m==0) break;
		cout<<ans[n][m]<<endl;
	}
	
	return 0;
}
