// Problem: C. Divan and bitwise operations
// Contest: Codeforces - Codeforces Round #757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
const ll mod=1e9+7;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> l(m+1),r(m+1),val(m+1);
		for(int i=1;i<=m;i++){
			cin>>l[i]>>r[i]>>val[i];
		}
		vector<int> out(n+1);
		ll ans=0;
		for(int i=0;i<31;i++){
			vector<int> d(n+2);
			for(int j=1;j<=m;j++){
				if(((val[j]>>i)&1)==0){
					d[r[j]+1]-=1;
					d[l[j]]+=1;
				}
			}
			
			for(int j=1;j<=n;j++){
				d[j]=d[j-1]+d[j];
				//cout<<d[j]<<" ";
			}
			//cout<<endl;
			ll cnt0=0,cnt1=0;
			for(int j=1;j<=n;j++){
				if(!d[j]){
					out[j]+=(1<<i);
					
					ans+=((1<<i)*(cnt0+1)%mod);
					//swap(cnt0,cnt1);
					ll sum=(cnt0+cnt1)%mod;
					cnt0=cnt1=sum;
					//cnt1=cnt1*2%mod;
					cnt1++;
					//ans+=((1<<i)*cnt0%mod)%mod;
				}else{
					ans+=((1<<i)*(cnt1)%mod);
					//swap(cnt0,cnt1);
					cnt0=cnt0*2%mod;
					cnt1=cnt1*2%mod;
					cnt0++;
				}
				ans%=mod;
			}
		}
		// for(int i=1;i<=n;i++){
			// cout<<out[i]<<" ";
		// }
		// cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}