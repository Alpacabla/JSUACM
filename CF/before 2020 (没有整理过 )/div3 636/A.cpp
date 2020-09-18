#include<bits/stdc++.h>
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
	ll i,j;
	ll n,m;
	ll div[50]={0};
	int t;
	div[0]=1;
	for(i=1,j=2;;i++){
		div[i]+=div[i-1]+j;
		//cout<<div[i]<<endl;
		if(div[i]>1e9) break;
		j<<=1;
	}
	cin>>t;
	while(t--){
		cin>>n;
		ll ans;
		for(j=1;j<=i;j++){
			if(n%div[j]==0){
				ans=n/div[j];
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}