#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=5e5+5;
ll sum[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t,n;
	ll i;
	for(i=3;i<=max_n;i+=2){
		sum[i]=sum[i-2]+((i-1)*4)*(i/2);
	}
	cin>>t;
	while(t--){
		cin>>n;
		cout<<sum[n]<<endl;
	}
	return 0;
}