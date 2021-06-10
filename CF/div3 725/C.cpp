// Problem: C. Number of Pairs
// Contest: Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.com/contest/1538/problem/C
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
		ll l,r;
		cin>>n>>l>>r;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a.begin()+1,a.end());
		ll ans=0;
		for(int i=1;i<n;i++){
			int k1=lower_bound(a.begin()+i+1,a.end(),l-a[i])-a.begin();
			int k2=upper_bound(a.begin()+i+1,a.end(),r-a[i])-a.begin();
			ans+=(k2-k1);
		}
		cout<<ans<<endl;
	}
	return 0;
}