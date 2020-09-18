#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int max_n=2e5+5;
const ll MOD=998244353;
ll ans[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n;
	int i;
	cin>>n;
	ans[1]=10;
	ans[2]=180;
	ll x1=81,x2=90;
	for(i=3;i<=n;i++){
		x2=(x2*10)%MOD;
		x1=(x1*10)%MOD;
		ans[i]=(2*x2%MOD+(i-2)*x1%MOD)%MOD;
	}
	for(i=n;i>=1;i--){
		cout<<ans[i]<<" ";
	}
	return 0;
}