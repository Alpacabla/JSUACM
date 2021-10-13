// Problem: E1. Rubik's Cube Coloring (easy version)
// Contest: Codeforces - Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/E1
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int max_n=1e5+5;
ll dp[65][6];

ll qpow(ll a,int b)
{
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin>>k;
	const ll mod=1e9+7;
	for(int i=0;i<6;i++){
		dp[1][i]=1;
	}
	int kk[6]={1,0,3,2,5,4};
	for(int i=2;i<=k;i++){
		for(int j=0;j<6;j++){
			for(int o=0;o<6;o++){
				for(int l=0;l<6;l++){
					if(j!=o&&kk[j]!=o&&j!=l&&kk[j]!=l){
						dp[i][j]+=(dp[i-1][o]*dp[i-1][l])%mod;
						dp[i][j]%=mod;
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=0;i<6;i++){
		ans=(ans+dp[k][i])%mod;
	}
	cout<<ans*qpow(6,mod-2)%mod*qpow(4,mod-2)%mod*qpow(4,mod-2)%mod<<endl;
	return 0;
}