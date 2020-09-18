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
	ll n,m;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(n%2){
			for(i=2;i<=n;i++){
				if(n%i==0) break;
			}
			cout<<n+i+2*(m-1)<<endl;
		}else{
			cout<<n+m*2<<endl;
		}
	}
	return 0;
}