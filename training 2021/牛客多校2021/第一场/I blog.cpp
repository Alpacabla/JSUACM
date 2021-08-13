#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define lowbit(a) ((a)&(-a))
const ll mod=998244353;
const int max_n=5e3+5;
int n;
ll dp[max_n][max_n];
ll sum[max_n],cnt[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<ll> inv(max_n);
	inv[1]=1;
	for(int i=2;i<=5000;i++){
		inv[i]=(mod-(mod/i))*inv[mod%i]%mod;
	}
	for(int i=n;i>=1;i--){
		ll cnt1=0,sum1=0;
		if(i!=n){
			for(int j=1;j<=n;j++){
				if(a[i+1]>a[j]){
					cnt[j]++;
					sum[j]=(sum[j]+dp[i+1][j])%mod;
				}
			}
		}
		for(int j=n;j>=1;j--){
			if(a[i]>a[j]){
				if(cnt1==0) dp[i][j]=2;
				dp[i][j]=1+inv[cnt1]*sum1%mod;
			}
			if(a[i]<a[j]){
				if(cnt[j]==0) dp[i][j]=2;
				dp[i][j]=1+inv[cnt[j]]*sum[j]%mod;
				cnt1++;
				sum1=(sum1+dp[i][j])%mod;
			}
		}
	}
	ll ans=0;
	int cnt1=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>a[j]){
				cnt1++;
				ans=(ans+dp[i][j])%mod;
			}
		}
	}
	cout<<ans<<endl;
	cout<<cnt1<<endl;
	cout<<ans*inv[cnt1]%mod<<endl;
	return 0;
}