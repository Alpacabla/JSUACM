// Problem: G. Minimal Coverage
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/G
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		vector<int> dp(2001,int_inf);
		dp[0]=0;
		for(int i=1;i<=n;i++){
			vector<int> temp(2001,int_inf);
			for(int j=0;j<=2000;j++){
				int k1=j-a[i],k2=j+a[i];
				if(k1<0){
					temp[0]=min(temp[0],dp[j]+(-k1));
				}else{
					temp[k1]=min(temp[k1],dp[j]);
				}
				if(k2<=2000){
					temp[k2]=max(k2,dp[j]);
				}
			}
			dp=temp;
		}
		int ans=int_inf;
		for(int i=0;i<=2000;i++){
			ans=min(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}