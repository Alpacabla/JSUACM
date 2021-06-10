// Problem: F. Interesting Function
// Contest: Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.com/contest/1538/problem/F
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
int num[10];
ll solve(int a)
{
	ll res=0;
	for(int i=0;i<=9;i++){
		res+=(a/num[i]);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	num[0]=1;
	for(int i=1;i<=9;i++){
		num[i]=num[i-1]*10;
	}
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		cout<<solve(r)-solve(l)<<endl;
	}
	return 0;
}