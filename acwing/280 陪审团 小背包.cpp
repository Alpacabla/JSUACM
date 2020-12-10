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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int dp[22][805],choose[22][805];
	int n,m;
	int now=0;
	while(cin>>n>>m){
		now++;
		vector<int> p(n),d(n);
		for(int i=0;i<n;i++){
			cin>>p[i]>>d[i];
		}
		memset(dp,-1,sizeof(dp));
		memset(choose,0,sizeof(dp));
		dp[0][400]=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<=800;j++){
				for(int k=20;k>=1;k--){
					if(j+p[i]-d[i]+400<=800&&dp[k-1][j+p[i]-d[i]+400]!=-1){
						if(dp[k][j]<dp[k-1][j+p[i]-d[i]+400]+p[i]+d[i]){
							//cout<<j<<endl;
							dp[k][j]=dp[k-1][j+p[i]-d[i]+400]+p[i]+d[i];
							choose[k][j]=i;
						}
					}
				}
			}
		}
		bool flag=true;
		int ans=-1,dd=0;
		for(int i=1;i<=400&&flag;i++){
			flag=true;
			if(dp[m][400+i]!=-1){
				flag=false;
				dd=i;
				ans=dp[m][400+i];
			}
			if(dp[m][i]!=-1){
				flag=false;
				dd=i;
				ans=max(ans,dp[m][i]);
			}
		}
		cout<<dd<<endl;
		cout<<ans<<endl;
		cout<<"Jury #"<<now<<endl;
		cout<<"Best jury has value "<<(ans+dd)/2<<" for prosecution and value "<<(ans-dd)/2<<" for defence:"<<endl;
	}

	return 0;
}