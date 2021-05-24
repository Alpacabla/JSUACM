// Problem: B. Sifid and Strange Subsequences
// Contest: Codeforces - Codeforces Round #722 (Div. 2)
// URL: https://codeforces.com/contest/1529/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		vector<int> k;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]<=0) ans++,k.push_back(a[i]);
		}
		sort(k.begin(),k.end());
		ll d=ll_inf;
		for(int i=1;i<k.size();i++){
			d=min(1ll*k[i]-k[i-1],d);
		}
		for(int i=1;i<=n;i++){
			if(a[i]>0&&a[i]<=d){
				ans++;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}