#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long int ll;
const int max_n=5e3+5;
int dp[max_n][max_n];
void init(int n)
{
	dp[0][0]=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(dp[i][j]==0){
				for(int k=1;i+k<=n;k++){
					for(int u=0;u*k+j<=n;u++){
						int o=u*k+j;
						if(i+k>o) dp[i+k][o]=1;
						else dp[o][i+k]=1;
					}
				}
				for(int k=1;j+k<=n;k++){
					for(int u=0;u*k+i<=n;u++){
						int o=u*k+i;
						if(j+k>o) dp[j+k][o]=1;
						else dp[o][j+k]=1;
					}
				}
			}
		}
	}
	// // for(int i=1;i<=n;i++){
	// // 	for(int j=1;j<=i;j++){
	// // 		cout<<i<<" "<<j<<endl;
	// // 		cout<<dp[i][j]<<endl;
	// // 	}
	// // }
	// cout<<1<<endl;
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(5e3);
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(a<b) swap(a,b);
		cout<<(dp[a][b]?"Alice":"Bob")<<endl;
	}
	return 0;
}