/*
link: 
tags: 
*/
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
		ll n;
		cin>>n;
		bool flag=true;
		ll ans=n;
		for(ll i=n;flag;i++){
			ll sum=0;
			ll t=i;
			while(t){
				sum+=(t%10);
				t/=10;
			}
			//cout<<sum<<endl;
			if(__gcd(i,sum)>1){
				ans=i;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}