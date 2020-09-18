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
int gcd(int a,int b){ return b==0?a:gcd(b,a%b); }
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int a,b,n;
		cin>>a>>b>>n;
		ll max1=(ll)max(a,b);
		ll k=(ll)(a/gcd(a,b)*b);
		while(n--){
			ll l,r,ans=0;
			cin>>l>>r;
			if(a==b){
				cout<<0<<endl;
				continue;
			}
			if(min(a,b)==1){
				cout<<0<<endl;
				continue;
			}
			if(l<=max1){
				int cnt=0;
				ll lim=min(max1,r);
				for(ll i=l;i<=lim;i++){
					if(i%a%b==i%b%a) cnt++;
				}
				ans-=cnt;
			}
			ans+=r-l+1;
			if((r-l+1)>=k){
				ans-=((((r-l+1)/k)-1)*max1);
			}
			if(r>=k){
				ans-=min(r%k+1,max1);
			}
			cout<<ans<<" ";
		}
		cout<<endl;
	}
	return 0;
}