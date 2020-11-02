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
	ll t;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		string s;
		cin>>s;
		ll dis=a/b;
		ll ans=0;
		ll i=0;
		while(i<s.size()&&s[i]=='0') i++;
		ll j=s.size()-1;
		while(j>=0&&s[j]=='0') j--;
		ll cnt1=0,cnt2=0;
		for(;i<=j;){
			while(i<=j&&s[i]=='1'){
				i++;
			}
			cnt1++;
			ll k=0;
			while(i<=j&&s[i]=='0'){
				i++;
				k++;
			}
			//cout<<k<<endl;
			if(k==0) continue;
			if(k<=dis){
				cnt2+=k;
				cnt1--;
			}
		}
		cout<<cnt1*a+cnt2*b<<endl;
	}
	return 0;
}