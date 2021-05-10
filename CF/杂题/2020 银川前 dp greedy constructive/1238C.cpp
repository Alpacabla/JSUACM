// Problem: B - Standard Free2play
// Contest: Virtual Judge - 构造dp贪心
// URL: https://vjudge.net/contest/437963#problem/B
// Memory Limit: 262 MB
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int h,n;
		cin>>h>>n;
		vector<int> a(n+1),dp(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		dp[1]=0;
		int s=2;
		if(a[2]+1==a[1]) s=3,dp[2]=1;
		for(int i=s;i<=n;i++){
			if(a[i]+1!=a[i-1]){
				dp[i]=dp[i-1]+1;
			}else{
				dp[i]=dp[i-2];
			}
		}
		int res=dp[n];
		if(a[n]==1) res=min(res,dp[n-1]);
		cout<<res<<endl;
	}
	return 0;
}