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
	int t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		ll l1,r1,l2,r2;
		ll ans=ll_inf;
		cin>>l1>>r1>>l2>>r2;
		if(r1<l2||l1>r2){
			if(l1>l2) swap(l1,l2);
			if(r1>r2) swap(r1,r2);
			ans=ll_inf;
			for(i=1;i<=n;i++){
				ll lim=min(i*(r2-l1),k);
				ans=min(ans,lim+(k-lim)*2+(l2-r1)*i);
			}
		}else{
			ll mid=max(r2,r1)-min(l1,l2)-abs(r2-r1)-abs(l2-l1);
			ll side=abs(r2-r1)+abs(l2-l1);
			if(mid*n>=k){
				ans=0;
			}else{
				k-=mid*n;
				if(side*n>=k){
					ans=k;
				}else{
					ans=side*n;
					k-=side*n;
					ans+=k*2;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}