#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
int dp[2005][2005];
int num[2005];
int main()
{
	int n,h;
	int l,r;
	int i,j;
	int t;
	scanf("%d %d %d %d",&n,&h,&l,&r);
	for(i=1;i<=n;i++){
		scanf("%d",num+i);
	}
	for(i=0;i<2005;i++){
		for(j=0;j<2005;j++){
			dp[i][j]=-INF;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=n;i++){
		for(j=0;j<h;j++){
			t=(j+num[i])%h;
			if(t>=l&&t<=r){
				dp[i][t]=max(dp[i][t],dp[i-1][j]+1);
			}else{
				dp[i][t]=max(dp[i][t],dp[i-1][j]);
			}
			t=(j+num[i]-1)%h;
			if(t>=l&&t<=r){
				dp[i][t]=max(dp[i][t],dp[i-1][j]+1);
			}else{
				dp[i][t]=max(dp[i][t],dp[i-1][j]);
			}
		}
	}
	int ans=0;
	for(i=0;i<h;i++){
		if(dp[n][i]>ans) ans=dp[n][i];
	}
	printf("%d\n",ans);
	return 0;
}