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
const ll mod=998244353;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n;
	vector<int> a(n+2);
	for(int i=1;i<=n+1;i++){
		cin>>a[i];
	}
	cin>>m;
	vector<int> x(m+1);
	for(int i=1;i<=m;i++){
		cin>>x[i];
	}
	for(int i=1;i<=m;i++){
		ll now=1;
		ll ans=0;
		for(int j=1;j<=n+1;j++){
			ans=(ans+now*a[j]%mod)%mod;
			now=now*x[i]%mod;
		}
		cout<<ans<<" ";
	}
	cout<<endl;
	return 0;
}