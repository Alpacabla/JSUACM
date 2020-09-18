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
	ll i,j;
	ll t;
	ll a,b,c,d;
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		ll ans=0;
		a-=b;
		if(a<=0){
			cout<<b<<endl;
		}else{
			ans=b;
			if(c<=d){
				cout<<-1<<endl;
			}else{
				ll x=c-d;
				if(a%x==0){
					a/=x;
				}else{
					a=a/x+1;
				}
				ans=a*c+ans;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}