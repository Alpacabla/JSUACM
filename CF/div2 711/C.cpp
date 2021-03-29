// Problem: C. Planar Reflections
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/contest/1498/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const ll mod=1e9+7;
ll sum[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		memset(sum,0,sizeof(ll)*(a+3));

		ll ans=1;
		for(int i=1;i<b;i++){
			if(i==1){
				for(int j=1;j<a;j++){
					sum[j]=1;
					ans++;
				}
				ans++;
				ans%=mod;
				continue;
			}
			if(i%2==0){
				for(int j=1;j<a;j++){
					sum[j]=(sum[j]+sum[j-1])%mod;
					ans=(ans+sum[j])%mod;
				}
			}else{
				for(int j=a-1;j>=1;j--){
					sum[j]=(sum[j]+sum[j+1])%mod;
					ans=(ans+sum[j])%mod;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}