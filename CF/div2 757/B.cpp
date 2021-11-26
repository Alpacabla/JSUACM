// Problem: B. Divan and a New Project
// Contest: Codeforces - Codeforces Round #757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/B
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
		vector<pair<int,int> > a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i].first;
			a[i].first=-a[i].first;
			a[i].second=i;
		}
		vector<int> v(2*n+1);
		for(int i=1;i<=n;i++){
			v[i]=i;
		}
		for(int i=n;i<=2*n;i++){
			v[i]=-(i-n+1);
		}
		sort(v.begin()+1,v.end(),[](const int a,const int b) -> bool{
			return abs(a)<abs(b);
		});
		sort(a.begin()+1,a.end());
		vector<int> ans(n+1);
		ll val=0;
		for(int i=1;i<=n;i++){
			ans[a[i].second]=v[i];
			val+=-a[i].first*1ll*abs(v[i]);
		}
		cout<<val*2<<endl;
		for(auto v:ans){
			cout<<v<<" ";
		}
		cout<<endl;
	}
	return 0;
}