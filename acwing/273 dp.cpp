/*
link: https://www.acwing.com/problem/content/275/
tags: easy dp
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
ll dp[2005][2005];
int num[2005],ind[2005];
ll solve(const int n)
{
	for(int i=1;i<=n;i++){
		ll last=dp[i-1][1];
		for(int j=1;j<=n;j++){
			int d=abs(num[i]-num[ind[j]]);
			last=min(last,dp[i-1][j]);
			dp[i][j]=last+d;
		}
	}
	ll res=ll_inf;
	for(int i=1;i<=n;i++){
		res=min(res,dp[n][i]);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>num[i];
		ind[i]=i;
	}
	sort(ind+1,ind+n+1,[](const int a,const int b) -> bool{
		return num[a]<num[b];
	});
	ll ans=solve(n);
	sort(ind+1,ind+n+1,[](const int a,const int b) -> bool{
		return num[a]>num[b];
	});
	ans=min(ans,solve(n));
	cout<<ans<<endl;
	return 0;
}
