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
int max1[max_n],max2[max_n];
int dp[max_n][6];
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,k,z;
		cin>>n>>k>>z;
		int ans=-1;
		dp[0][0]=0;
		max2[1]=0;
		max2[0]=0;
		for(i=1;i<=n;i++){
			cin>>num[i];
			dp[i][0]=dp[i-1][0]+num[i];
			if(i>=2){
				max2[i]=max(max2[i-1],num[i]+num[i-1]);
			}
		}
		k+=1;
		for(i=1;i<=k;i++){
			ans=max(dp[i][0],ans);
			if(i>=2){
				for(j=1;j<=z;j++){
					if(i+2*j>k+1){
						continue;
					}
					if(i+2*j==k+1){
						dp[i][j]=(max2[i]*(j-1))+num[i-1]+dp[i][0];
					}else{
						dp[i][j]=(max2[i]*(j))+dp[i][0];
					}
					ans=max(ans,dp[i][j]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}