// Problem: C. Carrying Conundrum
// Contest: Codeforces - Codeforces Round #742 (Div. 2)
// URL: https://codeforces.com/contest/1567/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
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
		string s;
		cin>>s;
		reverse(s.begin(),s.end());
		ll ans=0;
		vector<int> dp[2];
		for(int i=0;i<s.size();i++) s[i]-='0';
		dp[0].resize(s.size());
		dp[1].resize(s.size());
		for(int i=0;i<s.size();i+=2){
			if(i==0){
				dp[0][i]=s[i]+1;
				dp[1][i]=9-(s[i]+10-9)+1;
			}else{
				dp[0][i]=(s[i]+1)*dp[0][i-2];
				dp[1][i]=(9-(s[i]+10-9)+1)*dp[0][i-2];
				
				dp[0][i]+=(s[i])*dp[1][i-2];
				dp[1][i]+=(9-(s[i]-1+10-9)+1)*dp[1][i-2];
			}
		}
		
		for(int i=1;i<s.size();i+=2){
			if(i==1){
				dp[0][i]=s[i]+1;
				dp[1][i]=9-(s[i]+10-9)+1;
			}else{
				dp[0][i]=(s[i]+1)*dp[0][i-2];
				dp[1][i]=(9-(s[i]+10-9)+1)*dp[0][i-2];
				
				dp[0][i]+=(s[i])*dp[1][i-2];
				dp[1][i]+=(9-(s[i]-1+10-9)+1)*dp[1][i-2];
			}
		}
		if(s.size()<2) cout<<dp[0][s.size()-1]-2<<endl;
		else cout<<dp[0][s.size()-1]*dp[0][s.size()-2]-2<<endl;
	}
	return 0;
}