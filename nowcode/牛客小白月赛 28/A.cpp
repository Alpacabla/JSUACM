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
const int mod=1e9+7;
ll qpow(ll a,int b)
{
	ll res=1;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int main()
{
	int i,j;
	int t;
	int n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		ll res=qpow(n,m);
		ll t=res;
		res-=1;
		if(res<0) res+=mod;
		t=qpow(t,mod-2);
		printf("%d\n",(int)((res*t)%mod));
	}
	return 0;
}
