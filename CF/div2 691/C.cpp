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
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	vector<ll> b(m+1),a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//sort(a.begin()+1,a.end());
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	ll res=0;
	for(int i=2;i<=n;i++){
		res=gcd(a[i]-a[1],res);
	}
	for(int i=1;i<=m;i++){
		cout<<abs(gcd(a[1]+b[i],res))<<" ";
	}
	cout<<endl;
	return 0;
}