// Problem: C. Coin Rows
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1555/problem/C
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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> sum1(n+1),sum2(n+1);
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			sum1[i]=sum1[i-1]+a;
		}
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			sum2[i]=sum2[i-1]+a;
		}
		int ans=int_inf;
		for(int i=1;i<=n;i++){
			ans=min(ans,max(sum1[n]-sum1[i],sum2[i-1]));
		}
		cout<<ans<<endl;
	}
	return 0;
}