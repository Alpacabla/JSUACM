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
	ll n;
	int t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b>>n;
		ll min1=min(a,b);
		ll max1=max(a,b);
		a=min1,b=max1;
		int cnt=0;
		if(a>n||b>n){
			cout<<0<<endl;
			continue;
		}
		while(1){
			cnt++;
			if(cnt%2){
				a+=b;
				if(a>n) break;
			}else{
				b+=a;
				if(b>n) break;
			}

		}
		cout<<cnt<<endl;
	}
	return 0;
}