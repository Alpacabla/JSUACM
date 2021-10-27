// Problem: E. Staircases
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e3+5;
int dp[max_n][max_n][2];
bool vis[max_n][max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int ans=0;
	int n,m,q;
	cin>>n>>m>>q;
	int now=n*m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j][0]=dp[i][j][1]=1;
			if(i-1>0){
				dp[i][j][0]+=dp[i-1][j][1];
			}
			if(j-1>0){
				dp[i][j][1]+=dp[i][j-1][0];
			}
			ans+=dp[i][j][0]+dp[i][j][1];
		}
	}
	auto conv=[](int a,int b) -> int{
		if(vis[a][b]) return 0;
		int t1=dp[a][b][0],t2=dp[a][b][1];
		dp[a][b][0]=dp[a][b][1]=1;
		if(a-1>0){
			dp[a][b][0]+=dp[a-1][b][1];
		}
		if(b-1>0){
			dp[a][b][1]+=dp[a][b-1][0];
		}
		return dp[a][b][0]+dp[a][b][1]-t1-t2;
	};
	while(q--){
		int a,b;
		cin>>a>>b;
		bool flag=vis[a][b];
		vis[a][b]=!flag;
		if(!flag){
			ans-=dp[a][b][0]+dp[a][b][1];
			dp[a][b][0]=dp[a][b][1]=0;
			now--;
		}else{
			ans+=conv(a,b);
			now++;
		}
		for(int i=a;i<=n&&b<=m;i++){
			for(int j=b;j<=b+2&&j<=m;j++){
				if(i==a&&j==b){
					continue;
				}
				ans+=conv(i,j);
			}
			if(i!=a) b++;
		}
		cout<<ans-now<<endl;
	}
	return 0;
}