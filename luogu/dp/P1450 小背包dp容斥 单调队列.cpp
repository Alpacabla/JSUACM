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
#define int ll
ll cnt[5];
vector<ll> dp[5];
int a[5];
signed main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int n;
	for(int i=1;i<=4;i++){
		scanf("%lld",&a[i]);
	}
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		int m;
		for(int j=1;j<=4;j++){
			scanf("%lld",&cnt[j]);
			//cin>>cnt[j];
		}
		scanf("%lld",&m);
		for(int j=0;j<=4;j++){
			dp[j].resize(m+5);
		}
		dp[0][0]=1;
		for(int j=1;j<=4;j++){
			for(int d=0;d<a[j];d++){
				ll sum=0;
				int k;
				for(k=0;k<=cnt[j]&&d+k*a[j]<=m;k++){
					sum+=dp[j-1][d+k*a[j]];
					dp[j][d+k*a[j]]+=sum;
				}
				for(;d+k*a[j]<=m;k++){
					sum-=dp[j-1][d+(k-cnt[j]-1)*a[j]];
					sum+=dp[j-1][d+k*a[j]];
					dp[j][d+k*a[j]]+=sum;
				}
			}
			// for(int d=0;d<=m;d++){
			// 	cout<<dp[j][d]<<" ";
			// }
			// cout<<endl;
		}
		printf("%lld\n",dp[4][m]);
		for(int i=1;i<=4;i++){
			dp[i].clear();
		}
	}
	return 0;
}