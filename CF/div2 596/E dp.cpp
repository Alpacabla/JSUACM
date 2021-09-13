// Problem: E. Rock Is Push
// Contest: Codeforces - Codeforces Round #596 (Div. 2, based on Technocup 2020 Elimination Round 2)
// URL: https://codeforces.com/contest/1247/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
const int max_n=1e5+5;
char s[2005][2005];
int sum[2005][2005];
int sumsum[2005][2005];
int dp[2005][2005][2];
int sumdp[2005][2005][2];
int cntcnt[2005];
int lll[2005];
const int mod=1e9+7;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>(s[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			sum[i][j]+=sum[i][j+1]+(s[i][j]=='R');
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			sumsum[i][j]=sumsum[i+1][j]+(s[i][j]=='R');
		}
	}
	if(n==1&&m==1){
		cout<<1<<endl;
		return 0;
	}//该特判还是得特判
	sumdp[1][1][0]=sumdp[1][1][1]=1;
	for(int i=1;i<=m;i++){
		lll[i]=1;
	}
	for(int i=1;i<=n;i++){
		int l=1;
		int cnt=0;
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			while(l<j&&cnt+sum[i][j]>=(m-j+1)){
				
				l++;
				cnt-=(s[i][l]=='R');
			}
			dp[i][j][0]=((sumdp[i][j-1][1]-sumdp[i][l-1][1])%mod+mod)%mod;
			sumdp[i][j][0]=(sumdp[i-1][j][0]+dp[i][j][0])%mod;
			if(j!=1) cnt+=s[i][j]=='R';
			//该特判还是得特判
			
			while(lll[j]<i&&cntcnt[j]+sumsum[i][j]>=(n-i+1)){
				
				lll[j]++;
				cntcnt[j]-=s[lll[j]][j]=='R';
			}
			dp[i][j][1]=((sumdp[i-1][j][0]-sumdp[lll[j]-1][j][0])%mod+mod)%mod;
			sumdp[i][j][1]=(sumdp[i][j-1][1]+dp[i][j][1])%mod;
			if(i!=1) cntcnt[j]+=s[i][j]=='R';
			//该特判还是得特判
		}
	}
	cout<<(dp[n][m][0]+dp[n][m][1])%mod;
	return 0;
}