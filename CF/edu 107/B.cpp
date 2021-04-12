// Problem: B. GCD Length
// Contest: Codeforces - Educational Codeforces Round 107 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1511/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	ll z[10];
	z[1]=1;
	for(int i=2;i<=9;i++){
		z[i]=z[i-1]*10;
	}
	cin>>t;
	while(t--){
		int a,b,c;
		ll ans1,ans2;
		cin>>a>>b>>c;
		ans1=z[c];
		ans2=z[c];
		while(1){
			int cnt=0;
			ll k=ans1;
			while(k){
				cnt++;
				k/=10;
			}
			if(cnt==a){
				break;
			}
			ans1=ans1*3;
		}
		while(1){
			int cnt=0;
			ll k=ans2;
			while(k){
				cnt++;
				k/=10;
			}
			if(cnt==b){
				break;
			}
			ans2=ans2*7;
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}