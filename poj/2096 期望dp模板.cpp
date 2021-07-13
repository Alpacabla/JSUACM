// Problem: Collecting Bugs
// Contest: POJ - Northeastern Europe 2004
// URL: http://poj.org/problem?id=2096
// Memory Limit: 64 MB
// Time Limit: 10000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<cstdio>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
double dp[1005][1005];
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int n,s;
	scanf("%d%d",&n,&s);
	dp[n][s]=0;
	for(int i=n;i>=0;i--){
		for(int j=s;j>=0;j--){
			double _p1;
			if(i==n&&j==s) continue;
			//if(i==0&&j==0) _p1=1;
			_p1=(1-(1.0*i*j/n/s));
			dp[i][j]=1/_p1;
			if(j+1<=s) dp[i][j]+=1.0*dp[i][j+1]*i/n*(s-j)/s/_p1;
			if(i+1<=n) dp[i][j]+=1.0*dp[i+1][j]*(n-i)/n*j/s/_p1;
			if(i+1<=n&&j+1<=s) dp[i][j]+=1.0*dp[i+1][j+1]*(n-i)/n*(s-j)/s/_p1;
		}
	}
	printf("%.4lf\n",dp[0][0]);
	//cout<<dp[0][0]<<endl;
	return 0;
}