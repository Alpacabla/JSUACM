// Problem: E. Paint
// Contest: Codeforces - Codeforces Round #743 (Div. 2)
// URL: https://codeforces.com/contest/1573/problem/E
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int max_n=5e3+5;
int dp[max_n][max_n];
int a[max_n];
int last[max_n],nxt[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(last,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==a[i-1]) i--,n--;
		}
		memset(nxt,0,sizeof(int)*(n+1));
		
		for(int i=1;i<=n;i++){
			nxt[i]=last[a[i]];
			last[a[i]]=i;
		}
		for(int i=1;i<=n;i++){
			memset(dp[i],0,sizeof(int)*(n+1));
		}
		for(int i=1;i<n;i++){
			for(int l=1;l+i<=n;l++){
				int r=l+i;
				dp[l][r]=dp[l][r-1]+1;
				if(a[l]==a[r]) dp[l][r]=min(dp[l][r],dp[l+1][r-1]+1);
				for(int k=nxt[r];k>l;k=nxt[k]){
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
			}
		}
		cout<<dp[1][n]<<endl;
	}
	return 0;
}