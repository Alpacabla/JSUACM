// Problem: C. The Hard Work of Paparazzi
// Contest: Codeforces - Codeforces Global Round 11
// URL: https://codeforces.com/contest/1427/problem/C
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
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int r,n;
	cin>>r>>n;
	vector<int> t(n+1),x(n+1),y(n+1),dp(n+1,-int_inf);
	dp[0]=0;
	x[0]=1;
	y[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>x[i]>>y[i];
		int l=max(0,i-4*r);//可视范围应该改成4*r，而不是2*r
						   //虽然周期是2*r,但是2*r内的点不一定可以到达
						   //或者维护前缀max值，每次取至少i-2*r的前缀最值也行
		for(int j=l;j<i;j++){
			if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j]) dp[i]=max(dp[j]+1,dp[i]);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}