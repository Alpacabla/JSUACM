/*
link: https://codeforces.com/contest/1418/problem/A
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
	int t;
	cin>>t;
	while(t--){
		ll x,y,k;
		cin>>x>>y>>k;
		ll sum1=y*k+k;
		ll tot=(sum1-1)/(x-1);
		if((sum1-1)%(x-1)) tot++;
		cout<<tot+k<<endl;
	}
	return 0;
}
