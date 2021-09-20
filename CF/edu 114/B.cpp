// Problem: B. Combinatorics Homework
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
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
		int m;
		int a[3];
		cin>>a[0]>>a[1]>>a[2]>>m;
		sort(a,a+3);
		int l,r;
		if(a[2]<=a[0]+a[1]){
			l=0;
		}else{
			l=a[2]-a[0]-a[1]-1;
		}
		r=a[0]-1+a[1]-1+a[2]-1;
		if(m<=r&&m>=l) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}