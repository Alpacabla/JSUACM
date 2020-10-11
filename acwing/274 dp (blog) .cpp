/*
link: https://www.acwing.com/problem/content/description/276/
tags: dp 暴力dp
learned: 枚举某个位置被依赖的状态的时候如果不好枚举可以试试反过来枚举这个状态影响哪些状态
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
int c[205][205];
int dp[1005][205][205];
int v[1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k;
	int n,m;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>c[i][j];
		}
	}
	for(i=1;i<=m;i++){
		cin>>v[i];
	}
	memset(dp,0x3f3f,sizeof(dp));
	v[0]=3;
	dp[0][1][2]=0;
	dp[0][2][1]=0;
	for(i=0;i<m;i++){
		for(j=1;j<=n;j++){
			for(k=1;k<=n;k++){
				if(j==k||v[i]==k||v[i]==j) continue;
				int a=dp[i][j][k];				//卡常
				dp[i+1][j][k]=min(dp[i+1][j][k],a+c[v[i]][v[i+1]]);
				dp[i+1][v[i]][k]=min(dp[i+1][v[i]][k],a+c[j][v[i+1]]);
				dp[i+1][j][v[i]]=min(dp[i+1][j][v[i]],a+c[k][v[i+1]]);
			}
		}
	}
	int ans=int_inf;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			ans=min(ans,dp[m][i][j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
