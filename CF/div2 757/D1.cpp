// Problem: D1. Divan and Kostomuksha (easy version)
// Contest: Codeforces - Codeforces Round #757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/D1
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e7+5;
int cnt[max_n];
ll dp[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		cnt[a]++;
	}
	const int lim=5e6;
	for(int i=1;i<=lim;i++){
		for(int j=2*i;j<=lim;j+=i){
			cnt[i]+=cnt[j];
		}
	}
	
	
	
	ll ans=0;
	dp[1]=n;
	for(int i=1;i<=lim;i++){
		for(int j=2*i;j<=lim;j+=i){
			dp[j]=max(dp[j],dp[i]+(j-i)*1ll*cnt[j]);
		}
		ans=max(ans,dp[i]);
	}
	// for(int i=1;i<=10;i++){
		// cout<<dp[i]<<endl;
	// }
	cout<<ans<<endl;
	return 0;
}