/*
link: https://www.acwing.com/problem/content/314/
tags: 滚动数组 dp
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
int dp[5][41][41][41][41];
int cnt[5];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k,l,o;
	int n,m;
	cin>>n>>m;
	vector<int> num(n+1);
	for(i=1;i<=n;i++){
		cin>>num[i];
	}
	for(i=0;i<m;i++){
		int a;
		cin>>a;
		cnt[a-1]++;
	}
	memset(dp,-0x3f3f,sizeof(dp));
	dp[1][0][0][0][0]=num[1];
	for(i=2;i<=n;i++){
		int now=i%5;
		int a[4];
		for(j=0;j<4;j++){
			a[j]=min((i-1)/(j+1),cnt[j]);
		}
		for(j=0;j<=a[0];j++){
			for(k=0;k<=a[1];k++){
				for(l=0;l<=a[2];l++){
					o=(i-1-j-k*2-l*3)/4;
					if(j!=0) dp[now][j][k][l][o]=max(dp[now][j][k][l][o],dp[(now-1+5)%5][j-1][k][l][o]+num[i]);
					if(k!=0) dp[now][j][k][l][o]=max(dp[now][j][k][l][o],dp[(now-2+5)%5][j][k-1][l][o]+num[i]);
					if(l!=0) dp[now][j][k][l][o]=max(dp[now][j][k][l][o],dp[(now-3+5)%5][j][k][l-1][o]+num[i]);
					if(o!=0) dp[now][j][k][l][o]=max(dp[now][j][k][l][o],dp[(now-4+5)%5][j][k][l][o-1]+num[i]);
				}
			}
		}
	}
	cout<<dp[n%5][cnt[0]][cnt[1]][cnt[2]][cnt[3]]<<endl;
	return 0;
}
