// Problem: C. Slay the Dragon
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	int n;
	cin>>n;
	vector<ll> a(n+1);
	ll sum=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum+=a[i];
	
	sort(a.begin()+1,a.end());
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		ll x,y;
		cin>>x>>y;
		auto k=lower_bound(a.begin()+1,a.end(),x);
		ll ans=ll_inf;
		if(a.end()==k){
			ll temp=0;
			temp+=abs(x-*prev(k));
			ll v=sum-*prev(k);
			if(v<y) temp+=y-v;
			ans=min(ans,temp);
			cout<<ans<<endl;
			continue;
		}
		if(a.begin()+1==k){
			ll temp=0;
			ll v=sum-*k;
			if(v<y) temp+=y-v;
			ans=min(ans,temp);
			cout<<ans<<endl;
			continue;
		}
		ll temp=0;
		temp+=abs(x-*prev(k));
		ll v=sum-*prev(k);
		if(v<y) temp+=y-v;
		ans=min(ans,temp);
		
		
		temp=0;
		v=sum-*k;
		if(v<y) temp+=y-v;
		ans=min(ans,temp);
		cout<<ans<<endl;
	}
	return 0;
}