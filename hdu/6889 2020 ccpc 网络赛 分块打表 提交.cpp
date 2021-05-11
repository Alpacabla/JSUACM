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

const int sqn=1e5;
const ll lim=1e10;
ll qpow(ll a,int b,ll mod)
{
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
bool is_prime(ll num)
{
	if(num<=2||num%2==0) return num==2;
	int cnt=0;
	ll mod=num;
	num-=1;
	while(num%2==0) num/=2,cnt++;
	for(int i=0;i<TEST;i++){
		ll a=rand()%(mod-1)+1;
		a=qpow(a,num,mod);
		if(a==1||a==mod-1) continue;
		int j=0;
		for(;j<cnt;j++){
			a=a*a%mod;
			if(a==mod-1) break;
		}
		if(j==cnt) return false;
	}
	return true;
}
ll solve(ll n)
{
	ll x=n/sqn;
	ll res=sum[x];
	for(ll i=x*sqn+1;i<=n;i++){
		if(is_prime(i)){
			res+=i;
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll res=(n-1)*(n+4)%k*qpow(2,k-2,k)%k;
		if(n>=2) res-=2;
		res+=solve(n+1);
		res=res%mod;
		res=(res+mod)%mod;
		cout<<res<<endl;
	}
	return 0;
}