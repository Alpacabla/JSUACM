// Problem: D1. Up the Strip
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/D1
// Memory Limit: 128 MB
// Time Limit: 6000 ms
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
const int max_n=4e6+5;
int d[max_n];
int sum[max_n];
int dp[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,mod;
	cin>>n>>mod;
	dp[1]=1;
	sum[1]=1;
	int now=0;
	for(int i=2;i<=n;i++){
		// cout<<"i";
		// cout<<i<<endl;
		for(int j=2;j<=i;){
			//cout<<i<<" "<<j<<" "<<i/j<<endl;
			int v=i/j;
			//cout<<v<<endl;
			int k=i/v;
			//cout<<v<<" "<<k<<endl;
			
			// cout<<v<<" "<<k<<endl;
			// cout<<k-j+1<<endl;
			// cout<<k-v+1<<endl;
			// cout<<"vk"<<endl;
			dp[i]=(dp[i]+dp[v]*1ll*(k-j+1))%mod;
			j=k+1;
		}
		
		dp[i]=(dp[i]+sum[i-1])%mod;
		sum[i]=(sum[i-1]+dp[i])%mod;
		//cout<<sum[i-1]<<endl;
		//cout<<dp[i]<<endl;
	}
	cout<<dp[n]<<endl;
	// for(int i=2;i<=n;i++){
		// cout<<d[i]<<endl;
		// now+=d[i];
		// now%=mod;
// 		
		// dp[i]=(0ll+dp[i]+now+sum[i-1])%mod;
// 		
		// //if(i!=2){
			// dp[i]=(dp[i]+(i+1)/2)%mod;
		// //}
		// sum[i]=(0ll+sum[i-1]+dp[i])%mod;
		// for(int j=2;1ll*i*j<=n;j++){
			// int v=i*j;
			// int vv=(i)*(j+1)-1;
			// d[v]=(d[v]+dp[i])%mod;
			// if(vv+1>n) continue; 
			// d[vv+1]=(d[vv+1]-dp[i])%mod;
			// if(d[vv+1]<0) d[vv+1]+=mod;
		// }
	// }//cout<<dp[2]<<endl;
	// cout<<dp[n]<<endl;
	return 0;
}