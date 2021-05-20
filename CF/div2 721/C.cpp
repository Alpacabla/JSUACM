// Problem: C. Sequence Pair Weight
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/C
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
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		map<int,ll> mp;
		for(int i=1;i<=n;i++){
			mp[a[i]]+=i;
		}
		//map<int,ll> aa;
		ll ans=0;
		for(int i=n;i>=1;i--){
			ll k1=(mp[a[i]]-=i);
			//ll k2=(aa[a[i]]+=i);
			ans+=k1*(n-i+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}