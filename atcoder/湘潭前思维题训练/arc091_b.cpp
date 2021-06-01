// Problem: D - Remainder Reminder
// Contest: AtCoder - AtCoder Beginner Contest 090
// URL: https://atcoder.jp/contests/abc090/tasks/arc091_b?lang=en
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
	int n,k;
	cin>>n>>k;
	if(k==0){
		cout<<1ll*n*n<<endl;
		return 0;
	}
	ll sum=0;
	for(int i=k+1;i<=n;i++){
		ll t=n/i;
		sum+=t*(i-k);
		sum+=(n%i-k>=0?n%i-k+1:0);
	}
	cout<<sum<<endl;
	return 0;
}