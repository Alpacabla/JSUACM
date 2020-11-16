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
char s1[5005],s2[5005];
int dp[5005][5005];
int main()
{
	int i,j;
	int n,m;
	cin>>n>>m;
	scanf("%s%s",s1,s2);
	dp[0][0]=0;
	int k=min(n,m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(s1[i]==s2[j]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			}
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}