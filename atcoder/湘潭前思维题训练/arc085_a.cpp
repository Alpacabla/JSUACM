// Problem: C - HSI
// Contest: AtCoder - AtCoder Regular Contest 085
// URL: https://atcoder.jp/contests/arc085/tasks/arc085_a?lang=en
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
	ll n,m;
	cin>>n>>m;
	cout<<((m*1900)+(n-m)*100)*(int)pow(2,m)<<endl;
	return 0;
}