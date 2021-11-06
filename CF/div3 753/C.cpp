// Problem: C. Minimum Extraction
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/C
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
		vector<ll>a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		vector<ll> sum(n+1);
		sort(a.begin()+1,a.end());
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		// if(n==1||a[1]>=0){
			// cout<<a[1]<<endl;
		// }else{
			ll ans=-ll_inf;
			ll temp=0;
			for(int i=1;i<=n;i++){
				a[i]+=temp;
				ans=max(ans,a[i]);
				temp+=-a[i];
			}
			cout<<ans<<endl;
		//}
	}
	return 0;
}