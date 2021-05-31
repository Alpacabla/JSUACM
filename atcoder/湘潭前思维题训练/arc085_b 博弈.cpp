// Problem: D - ABS
// Contest: AtCoder - AtCoder Regular Contest 085
// URL: https://atcoder.jp/contests/arc085/tasks/arc085_b
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
	int n,k,z;
	cin>>n>>k>>z;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1){
		cout<<abs(a[1]-z)<<endl;
	}else{
		cout<<max(abs(a[n]-z),abs(a[n]-a[n-1]))<<endl;
	}
	/*vector<int> dp[2],a[2];
	for(int i=0;i<2;i++) dp[i].resize(n+1),a[i].resize(n+1);
	a[0][0]=z;
	a[1][0]=k;
	for(int i=1;i<=n;i++) {cin>>a[0][i];a[1][i]=a[0][i];}
	
	for(int i=n;i>=1;i--){
		dp[0][i]=abs(a[0][i-1]-a[0][n]);
		for(int j=i+1;j<=n;j++){
			dp[0][i]=max(dp[0][i],dp[1][j]);
		}
		dp[1][i]=abs(a[1][i-1]-a[1][n]);
		for(int j=i+1;j<=n;j++){
			dp[1][i]=min(dp[1][i],dp[0][j]);
		}
	}
	cout<<dp[0][1]<<endl;*/
	return 0;
}