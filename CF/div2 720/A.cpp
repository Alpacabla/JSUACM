// Problem: A. Nastia and nearly Good Numbers
// Contest: Codeforces - Codeforces Round #720 (Div. 2)
// URL: https://codeforces.com/contest/1521/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		if(b==1){
			cout<<"NO"<<endl;
		}else{
			if(b!=2){
				cout<<"YES"<<endl;
				cout<<a<<" "<<(b-1)*a<<" "<<a*b<<endl;
			}else{
				cout<<"YES"<<endl;
				cout<<a<<" "<<3*a<<" "<<4*a<<endl;
			}
		}
	}
	return 0;
}