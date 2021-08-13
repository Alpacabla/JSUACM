// Problem: D. Say No to Palindromes
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1555/problem/D
// Memory Limit: 256 MB
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
const int max_n=2e5+5;
int dp[9][max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	string ss="abc";
	vector<int> a(3);
	a[0]=0,a[1]=1,a[2]=2;
	int tot=0;
	do{
		for(int i=0;i<s.size();i++){
			dp[tot][i+1]=(s[i]!=ss[a[i%3]])+dp[tot][i];
		}
		tot++;
	}while(next_permutation(a.begin(),a.end()));
	while(m--){
		int a,b;
		cin>>a>>b;
		int ans=int_inf;
		for(int i=0;i<tot;i++){
			ans=min(ans,dp[i][b]-dp[i][a-1]);
		}
		cout<<ans<<endl;
	}
	return 0;
}