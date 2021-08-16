// Problem: B. Mocha and Red and Blue
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/B
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
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> dp[2];
		dp[0].resize(n+1),dp[1].resize(n+1);
		string s;
		string ans="";
		cin>>s;
		for(int i=0;i<n;i++){
			if(s[i]=='?'){
				dp[0][i+1]=min(dp[1][i],dp[0][i]+1);
				dp[1][i+1]=min(dp[0][i],dp[1][i]+1);
			}
			if(s[i]=='B'){
				dp[0][i+1]=int_inf;
				dp[1][i+1]=min(dp[0][i],dp[1][i]+1);
			}
			if(s[i]=='R'){
				dp[1][i+1]=int_inf;
				dp[0][i+1]=min(dp[1][i],dp[0][i]+1);
			}
		}
		int sta;
		if(dp[0][n]>dp[1][n]) sta=1;
		else sta=0;
		for(int i=n;i>=1;i--){
			ans+=(sta?"B":"R");
			if(dp[sta][i]==dp[!sta][i-1]) sta=!sta;
			if(dp[sta][i]==dp[sta][i-1]+1) sta=sta;
		}
		reverse(ans.begin(),ans.end());
		cout<<ans<<endl;
	}
	return 0;
}