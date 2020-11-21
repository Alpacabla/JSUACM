/*
link: 
tags: 
*/
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
const ll mod=998244353;
ll dp[max_n];
ll qpow(ll a,int b)
{
	ll res=1;
	while(b){
		if(b&1) res=(res*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return res;
}
ll pow2[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	dp[0]=0;
	dp[1]=1;
	for(int i=2;i<=n;i++){
		dp[i]=(dp[i-1]+dp[i-2])%mod;
	}
	pow2[0]=1;
	ll ans=dp[n];
	for(int i=1;i<=n;i++){
		pow2[i]=(pow2[i-1]*2)%mod;
	}
	//cout<<dp[n]<<" "<<pow2[n]<<endl;
	cout<<(dp[n]*qpow(pow2[n],(int)mod-2))%mod<<endl;
	return 0;
}