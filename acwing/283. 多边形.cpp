/*
link: https://www.acwing.com/problem/content/285/
tags: 区间dp 唯一要注意的是要同时维护最大最小
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
char ch[55];
int num[55];
int ans[55];
int dp[55][55][2];
int solve(vector<int> &a,vector<char> &b,int n)
{
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j][0]=int_inf;
			dp[i][j][1]=-int_inf;
		}
	}
	for(int i=1;i<=n;i++){
		dp[i][i][0]=dp[i][i][1]=a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i;j++){
			for(int k=j;k<j+i;k++){
				int now[4];
				if(b[k+1]=='t'){
					int cnt=0;
					for(int o=0;o<2;o++){
						for(int l=0;l<2;l++){
							now[cnt++]=dp[j][k][o]+dp[k+1][j+i][l];
						}
					}
				}else{
					int cnt=0;
					for(int o=0;o<2;o++){
						for(int l=0;l<2;l++){
							now[cnt++]=dp[j][k][o]*dp[k+1][j+i][l];
						}
					}
				}
				for(int o=0;o<4;o++){
					dp[j][j+i][0]=min(dp[j][j+i][0],now[o]);
					dp[j][j+i][1]=max(dp[j][j+i][1],now[o]);
				}
			}
		}
	}
	return dp[1][n][1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ch[i]>>num[i];
	}
	int max1=-1;
	for(int i=1;i<=n;i++){
		vector<int> a(n+1);
		vector<char> b(n+1);
		for(int j=1,k=i-1;j<=n;j++,k++){
			a[j]=num[k%n+1];
			b[j]=ch[k%n+1];
		}
		ans[i]=solve(a,b,n);
		max1=max(max1,ans[i]);
	}
	cout<<max1<<endl;
	for(int i=1;i<=n;i++){
		if(ans[i]==max1) cout<<i<<" ";
	}
	cout<<endl;
	return 0;
}