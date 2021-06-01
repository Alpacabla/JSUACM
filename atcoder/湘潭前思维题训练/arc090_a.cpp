// Problem: C - Candies
// Contest: AtCoder - AtCoder Beginner Contest 087
// URL: https://atcoder.jp/contests/abc087/tasks/arc090_a?lang=en
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
	int n;
	cin>>n;
	vector<int> a[2],sum[2];
	
	a[0].resize(n+1);
	a[1].resize(n+1);
	sum[0].resize(n+1);
	sum[1].resize(n+1);
	for(int i=0;i<2;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			sum[i][j]=sum[i][j-1]+a[i][j];
		}
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		ans=max(ans,sum[0][i]+sum[1][n]-sum[1][i-1]);
	}
	cout<<ans<<endl;
	return 0;
}