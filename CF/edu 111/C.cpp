// Problem: C. Manhattan Subarrays
// Contest: Codeforces - Educational Codeforces Round 111 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1550/problem/C
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
bool solve(int l,int r,vector<int> &a)
{
	for(int i=l;i<=r;i++){
		for(int j=i+1;j<=r;j++){
			for(int o=j+1;o<=r;o++){
				if(a[i]<=a[j]&&a[j]<=a[o]){
					return false;
				}
				if(a[i]>=a[j]&&a[j]>=a[o]){
					return false;
				}
			}
		}
	}
	return true;
}
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
		ll ans=0;
		for(int i=1;i<=n;i++){
			int l=i;
			for(int j=max(1,i-4);j<=i;j++){
				if(solve(j,i,a)){
					l=j;
					break;
				}
			}
			ans+=i-l+1;
		}
		cout<<ans<<endl;
	}
	return 0;
}