// Problem: C. Moamen and XOR
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/C
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
const int max_n=2e5+5;
const ll mod=1e9+7;
ll pow2[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	pow2[0]=1;
	for(int i=1;i<=2e5;i++){
		pow2[i]=pow2[i-1]*2%mod;
	}
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		if(k==0){
			cout<<1<<endl;
			continue;
		}
		if(n%2==1){
			int m=n;
			vector<ll> sum(k+1),sum1(k+1);
			sum[0]=1;
			for(int i=1;i<=k;i++){
				sum[i]=sum[i-1]*(pow2[m-1]+1)%mod;
			}
			cout<<sum[k]<<endl;
		}else{
			int m=n;
			vector<ll> sum(k+1),sum1(k+1);
			sum[0]=1;
			for(int i=1;i<=k;i++){
				sum[i]=sum[i-1]*(pow2[m-1]-1)%mod;
			}
			sum1[0]=1;
			for(int i=1;i<=k;i++){
				sum1[i]=sum1[i-1]*(pow2[m])%mod;
			}
			ll ans=sum[k];
			//cout<<ans<<endl;
			for(int i=1;i<=k;i++){
				ans=(ans+(sum[i-1]*sum1[k-i]%mod))%mod;
			}
			cout<<ans<<endl;
		}
		// int cnt=0;
		// for(int i=0;i<(1<<3);i++){
			// for(int j=0;j<(1<<3);j++){
				// for(int o=0;o<(1<<3);o++){
					// for(int l=0;l<(1<<3);l++){
						// for(int k=0;k<(1<<3);k++)
						// if((i&j&o&l&k)>=(k^i^j^o^l)){
							// cnt++;
						// }
					// }
				// }
			// }
		// }
		// cout<<cnt<<endl;
		// if(m%2==1){
			// m++;
		// }
		
		// ll ans=sum[k];
		// cout<<ans<<endl;
		// if(n%2==0){
			// for(int i=1;i<=n;i++){
				// ans=(ans+(sum[i-1]*sum1[n-i]%mod))%mod;
			// }
		// }else{
			// ans+=1;
		// }
		// cout<<ans<<endl;
	}
	return 0;
}