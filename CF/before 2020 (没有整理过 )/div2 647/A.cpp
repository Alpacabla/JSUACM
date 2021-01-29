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
	int i,j;
	ll a,b;
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(a==b){
			cout<<0<<endl;
			continue;
		}
		ll c=max(a,b);
		ll d=min(a,b);
		int flag=0;
		ll ans;
		if(c%d==0){
			ll x=c/d;
			if(x%2==0){
				int len=0;
				while(x!=1){
					int k=1;
					if(x%8==0){
						len++;
						x>>=3;
						k=0;
					}else if(x%4==0){
						x>>=2;
						len++;k=0;
					}else if(x%2==0){
						x>>=1;
						len++;k=0;
					}
					if(k) break;
				}
				if(x!=1){
					flag=0;
				}else{
					ans=len;
					flag=1;
				}
			}
		}
		if(flag) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}