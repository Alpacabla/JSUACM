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
const int max_n=1e5+5;
const ll mod=1e9+7;
ll qpow(ll a,int b)
{
	ll res=1;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
const ll inv6=qpow(6,mod-2);
const ll inv2=qpow(2,mod-2);
const ll inv4=qpow(4,mod-2);
const ll inv3=qpow(3,mod-2);
ll sum1(ll n)
{
	return n*(n+1)%mod*inv2%mod;
}
ll sum2(ll n)
{
	return n*(n+1)%mod*(2*n+1%mod)%mod*inv6%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		n%=mod;
		ll max1=n*n%mod*n%mod*(n+1)%mod*((2*n+1)%mod)%mod*inv6%mod*(1+n)%mod*n%mod*inv2%mod;
		// ll min1=n*n%mod*(n+1)%mod*(n+1)%mod*(2*n+1)%mod*inv6%mod;
		// cout<<min1<<endl;
		// min1=(min1+n*n%mod*(n+1)%mod*(n+1)%mod*inv4%mod)%mod;
		// cout<<min1<<endl;
		// min1=(min1-n*(n+1)%mod*(2*n+1)%mod*inv6%mod+mod)%mod;
		// cout<<min1<<endl;
		// min1=(min1-n*(n+1)%mod+mod)%mod;
		// cout<<(min1+1)%mod<<endl;
		ll min1=2*sum1(n)%mod*sum2(n)%mod;
		min1=(min1+sum1(n)*sum1(n)%mod)%mod;
		min1=(min1-sum2(n)%mod+mod)%mod;
		min1=(min1-3*sum1(n)%mod+mod)%mod;
		cout<<(min1+2)%mod<<endl;
		cout<<max1<<endl;
	}
	return 0;
}