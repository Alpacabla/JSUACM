// Problem: D. Power Products
// Contest: Codeforces - Codeforces Round #596 (Div. 2, based on Technocup 2020 Elimination Round 2)
// URL: https://codeforces.com/contest/1247/problem/D
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
//#define endl '\n'
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
	int n,k;
	cin>>n>>k;
	vector<int> vis(1e5+1);
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		vis[a]++;
	}
	vector<ll> v;
	for(int i=1;i<=1e5;i++){
		ll x=1;
		for(int j=1;j<=k&&x<=1e10;j++){
			x*=i;
		}
		if(x>1e10) break;
		v.push_back(x);
	}
	ll ans=0;
	for(int i=1;i<=1e3;i++){
		//if(vis[i]){
			ll l=i*i,r=i*1e5;
			int k1=(int)(lower_bound(v.begin(),v.end(),l)-v.begin());
			int k2=(int)(upper_bound(v.begin(),v.end(),r)-v.begin());
			cout<<k1<<" "<<k2<<endl;
			for(int j=k1;j<k2;j++){
				if(v[j]%i==0){
					ans+=(v[j]/i==i?(1ll+vis[i]-1)*(vis[i]-1)/2:vis[i]*vis[v[j]/i]);
				}
			}
		//}
	}
	cout<<ans<<endl;
	return 0;
}