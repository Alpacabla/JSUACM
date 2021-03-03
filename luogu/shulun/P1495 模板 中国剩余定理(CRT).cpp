/*
link: https://www.luogu.com.cn/problem/P1495
tags: exgcd 中国剩余定理模板
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
ll Exgcd(ll a, ll b, ll &x, ll &y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  ll d = Exgcd(b, a % b, x, y);
  ll t = x;
  x = y;
  y = t - (a / b) * y;
  return d;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll pro=1;
	cin>>n;
	vector<ll> a(n+1),b(n+1);
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		pro*=b[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		ll x,y;
		Exgcd(pro/b[i],b[i],x,y);
		ans+=(a[i]*x%pro*pro/b[i]%pro)%pro;
		ans%=pro;
	}
	while(ans<0) ans+=pro;
	cout<<ans<<endl;
	return 0;
}