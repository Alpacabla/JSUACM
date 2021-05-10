// Problem: A - Labs
// Contest: Virtual Judge - 构造dp贪心
// URL: https://vjudge.net/contest/437963#problem/A
// Memory Limit: 262 MB
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
	int n;
	cin>>n;
	int tot=0;
	vector<vector<int> >dp(n+1,vector<int> (n+1));
	for(int i=1;i<=n;i++){
		if(i%2)
			for(int j=1;j<=n;j++){
				dp[j][i]=++tot;
			}
		else 
			for(int j=n;j>=1;j--){
				dp[j][i]=++tot;
			}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	return 0;
}