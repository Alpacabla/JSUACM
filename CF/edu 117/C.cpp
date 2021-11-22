// Problem: C. Chat Ban
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1612/problem/C
// Memory Limit: 512 MB
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
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		// ll l=1,r=b,res=1;
		// ll ans=0;
		// while(l<=r){
			// ll mid=(l+r)>>1;
			// if(mid*mid<=b){
				// l=mid+1;
				// res=mid;
			// }else{
				// r=mid-1;
			// }
		// }
		ll d=b;
		ll res=a;
		
		ll now=res;
		//ll out=res*2-1;
		ll ans=0;
		if(d<=(now+1)*now/2){
			ll l=0,r=now,res=0;
			while(l<=r){
				ll mid=(l+r)>>1;
				if((1+mid)*mid/2<=d){
					l=mid+1;
					res=mid;
				}else{
					r=mid-1;
				}
			}
			// cout<<'v'<<endl;
			// cout<<res<<endl;
			if(d!=((res+1)*res/2)) ans++;
			ans+=res;
		}else{
			ans+=now;
			ll l=0,r=now-1,res=0;
			d-=(now+1)*now/2;
			while(l<=r){
				ll mid=(l+r)>>1;
				if((now-1+now-mid)*mid/2<=d){
					l=mid+1;
					res=mid;
				}else{
					r=mid-1;
				}
			}
			if(d!=(now-1+now-res)*res/2&&res!=now-1) ans++;
			ans+=res;
		}
		//cout<<ans<<endl;
		cout<<min(a*2-1ll,ans)<<endl;
	}
	return 0;
}