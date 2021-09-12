// Problem: C. Jury Meeting
// Contest: Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1569/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
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
	int t;
	vector<int> xx(2e5+1);
	const int mod=998244353;
	xx[0]=1;
	for(int i=1;i<=2e5;i++){
		xx[i]=xx[i-1]*1ll*i%mod;
	}
	
	vector<int> invx(2e5+1);
	invx[0]=1;
	auto qpow=[](ll a,int b,const int mod) -> int{
		ll res=1;
		while(b){
			if(b&1){
				res=res*a%mod;
			}
			a=a*a%mod;
			b>>=1;
		}
		return res;
	};
	for(int i=1;i<=2e5;i++){
		invx[i]=qpow(xx[i],mod-2,mod);
	}
	auto C=[&invx,&xx](int a,int b) -> ll {
		return xx[a]*1ll*invx[a-b]%mod*invx[b]%mod;
	};
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		
		sort(a.begin()+1,a.end());
		if(a[n]==a[n-1]){
			cout<<xx[n]<<endl;
		}else{
			if(a[n-1]+1!=a[n]){
				cout<<0<<endl;
			}else{
				int cnt=0;
				for(int i=n-1;i>=1;i--){
					if(a[i]==a[n-1]){
						cnt++;
					}else{
						break;
					}
				}
				ll ans=xx[n];
				ans=ans-C(n,cnt+1)*xx[cnt]%mod*xx[n-(cnt+1)]%mod;
				ans=(ans+mod)%mod;
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}