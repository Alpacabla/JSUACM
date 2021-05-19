// Problem: D. Armchairs
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1525/problem/D
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
const int max_n=5e3+5;
int dp[max_n][max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(1),b(1),d(n+1);
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i]) a.push_back(i);
		else b.push_back(i);
	}
	int k1=b.size()-1,k2=a.size()-1;
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<=k1;i++){
		dp[i][0]=0;
	}
	for(int i=1;i<=k1;i++){
		for(int j=1;j<=k2;j++){
			dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+abs(b[i]-a[j]));
		}
	}
	cout<<dp[k1][k2]<<endl;
	return 0;
}