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
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		vector<vector<double> >dp(n+1,vector<double>(m+1));
		vector<vector<double> >p[3];
		for(int i=0;i<3;i++){
			p[i].resize(n+1);
			for(int j=1;j<=n;j++){
				p[i][j].resize(m+1);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int k=0;k<3;k++){
					scanf("%lf",&p[k][i][j]);
				}
			}
		}
		dp[n][m]=0;
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				if(i==n&&j==m) continue;
				if(abs(p[0][i][j]-1)<=1e-8) continue;
				dp[i][j]=2/(1-p[0][i][j]);
				if(i+1<=n) dp[i][j]+=p[2][i][j]*dp[i+1][j]/(1-p[0][i][j]);
				if(j+1<=m) dp[i][j]+=p[1][i][j]*dp[i][j+1]/(1-p[0][i][j]);
			}
		}
		printf("%.3lf\n",dp[1][1]);
	}
	
	return 0;
}