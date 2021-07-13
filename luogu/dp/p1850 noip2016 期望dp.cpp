// Problem: #262. 【NOIP2016】换教室
// Contest: UOJ
// URL: https://uoj.ac/problem/262
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e3+5;
const int max_m=9e4+5;
//int edge[max_n][max_n];
double dp[2][max_n][2];
double p[max_n];
int ddd[max_n][max_n];
int c[max_n],d[max_n];
int dis(int a,int b)
{
	return ddd[a][b];
}
void init(int n)
{
	//memset(ddd,0x3f,sizeof(ddd));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				ddd[j][k]=ddd[k][j]=min(ddd[j][k],ddd[j][i]+ddd[i][k]);
			}
		}
	}
}
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int n,m,v,e;
	scanf("%d%d%d%d",&n,&m,&v,&e);
	for(int i=1;i<=n;i++){
		scanf("%d",c+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",d+i);
	}
	for(int i=1;i<=n;i++){
		scanf("%lf",p+i);
	}
	memset(ddd,0x3f,sizeof(ddd));
	for(int i=1;i<=e;i++){
		int a,b,val;
		scanf("%d%d%d",&a,&b,&val);
		ddd[a][b]=min(ddd[a][b],val);
		ddd[b][a]=min(ddd[b][a],val);
	}
	for(int i=1;i<=v;i++)
		ddd[i][i]=0;
	init(v);
	memset(dp,127,sizeof(dp));
	int k=0;
	dp[!k][0][0]=0;
	if(m!=0) dp[!k][1][1]=0;
	for(int i=2;i<=n;i++){
		int t1=dis(d[i],c[i-1]);
		int t2=dis(c[i],c[i-1]);
		int t3=dis(c[i],d[i-1]);
		int t4=dis(d[i],d[i-1]);
		
		for(int j=0;j<=m;j++){
			dp[k][j][0]=dp[k][j][1]=1e18;
			if(j-1>=0){
				dp[k][j][1]=dp[!k][j-1][0]+t1*p[i]+t2*(1-p[i]);
				if(j>1) dp[k][j][1]=min(dp[k][j][1],
					(dp[!k][j-1][1]+t1*(p[i])*(1-p[i-1])+t2*(1-p[i])*(1-p[i-1])+t3*(1-p[i])*(p[i-1])+t4*(p[i])*(p[i-1])));
			}
			dp[k][j][0]=dp[!k][j][0]+t2;
			if(j>0) dp[k][j][0]=min(dp[k][j][0],
				dp[!k][j][1]+t2*(1-p[i-1])+t3*(p[i-1]));
		}
		k=!k;
	}
	double ans=1e18;
	for(int i=0;i<=m;i++){
		if(i==0){
			ans=min(ans,dp[!k][i][0]);
		}else{
			ans=min(ans,min(dp[!k][i][0],dp[!k][i][1]));
		}
	}
	//cout<<ans<<endl;
	printf("%.2lf\n",ans);
	
	return 0;
}