// Problem: D. Maximum Sum of Products
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1519/problem/D
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
const int max_n=5e3+5;
ll dp1[max_n][max_n];
ll a[max_n],b[max_n];
ll x[max_n],xx[max_n];
ll solve(int n)
{
	for(int i=1;i<=n;i++){
		dp1[i][i]=a[i]*b[i];
		x[i]=a[i]*b[i]+x[i-1];
	}
	for(int i=n;i>=1;i--){
		xx[i]=xx[i+1]+a[i]*b[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int l=1;l+i<=n;l++){
			int r=l+i;
			dp1[l][r]=dp1[l+1][r-1]+a[r]*b[(l)]+a[l]*b[r];
		}
	}
	ll res=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			res=max(res,dp1[j][i]+x[j-1]+xx[i+1]);
		}
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		cin>>b[j];
	}
	cout<<solve(n)<<endl;
	return 0;
}