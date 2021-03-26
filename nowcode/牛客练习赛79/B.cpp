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
	int i,j;
	int n;
	int ans=0;
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		int g=__gcd(a,b);
		a/=g;
		b/=g;
		int cnt1=0,cnt2=0;
		while(a%3==0&&b%5==0){
			a/=3;
			b/=5;
			ans++;
		}
		while(a%5==0&&b%3==0){
			a/=5;
			b/=3;
			ans++;
		}
		while(a%5==0){
			a/=5;
			ans+=2;
		}
		while(b%5==0){
			b/=5;
			ans+=2;
		}
		while(a%3==0){
			a/=3;
			ans++;
		}
		while(b%3==0){
			b/=3;
			ans++;
		}
		if(a!=1||b!=1){
			ans=-1;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}