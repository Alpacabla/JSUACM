// Problem: B. AND Sequences
// Contest: Codeforces - Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
// URL: https://codeforces.com/contest/1513/problem/B
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
const int max_n=2e5+5;
const ll mod=1e9+7;
ll x[max_n],inv[max_n];
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
inline void init(const int m)
{
	x[0]=1;
	for(int i=1;i<=m;i++){
		x[i]=x[i-1]*i%mod;
		inv[i]=qpow(x[i],mod-2);
	}
	inv[0]=1;
	return ;
}
ll C(int a,int b)
{
	return x[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	init(2e5);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll ans;
		vector<bool> vis(n+1);
		for(int i=1;i<=n;i++) vis[i]=true;
		for(int i=0;i<=31;i++){
			vector<bool> vis1(n+1);
			bool flag=true;
			for(int j=1;j<=n;j++){
				if(((a[j]>>i)&1)==0){
					if(vis[j]){
						vis1[j]=true;
					}
					flag=false;
				}
			}
			if(!flag){
				for(int j=1;j<=n;j++){
					vis[j]=vis1[j];
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				cnt++;
			}
		}
		if(cnt<2) cout<<0<<endl;
		else {
			ans=C(cnt,2)*2%mod*x[n-2]%mod;
			cout<<ans<<endl;
		}
	}
	return 0;
}