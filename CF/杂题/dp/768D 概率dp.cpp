// Problem: D. Jon and Orbs
// Contest: Codeforces - Divide by Zero 2017 and Codeforces Round #399 (Div. 1 + Div. 2, combined)
// URL: https://codeforces.com/problemset/problem/768/D
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
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k,q;
	cin>>k>>q;
	vector<int> p(q);
	int max1=-1;
	for(int i=0;i<q;i++){
		cin>>p[i];
		max1=max(max1,p[i]);
	}
	vector<int> ans(q);
	vector<double> dp[2];
	dp[0].resize(k+1),dp[1].resize(k+1);
	int z=0;
	int cnt=0;
	dp[1][k]=1.0;
	while(1){
		cnt++;
		for(int i=0;i<=k;i++){
			dp[z][i]=dp[!z][i]*(k-i)/k+dp[!z][i+1]*(i+1)/k;
		}
		for(int i=0;i<q;i++){
			if(!ans[i]){
				if(dp[z][0]>1.0*p[i]/2000){
					ans[i]=cnt;
				}
			}
		}
		if(dp[z][0]>1.0*max1/2000){
			break;
		}
		z=!z;
	}
	for(int i=0;i<q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}