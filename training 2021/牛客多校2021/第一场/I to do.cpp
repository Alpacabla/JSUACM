#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define lowbit(a) ((a)&(-a))
const ll mod=998244353;
const int max_n=5e3+5;
ll f[max_n][max_n],g[max_n][max_n];
int ibit[max_n][max_n],jbit[max_n][max_n];
int cibit[max_n][max_n],cjbit[max_n][max_n];
int n;
void add(int *bit,int a,int val)
{
	while(a){
		bit[a]=(bit[a]+val)%mod;
		a-=lowbit(a);
	}
	return ;
}
int query(int *bit,int a)
{
	int res=0;
	while(a<=n){
		res=(res+bit[a])%mod;
		a+=lowbit(a);
	}
	return res;
}
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
		for(int j=n;j>=1;j--){
			int cnt=0;
			for(int k=j+1;k<=n;k++){
				if(a[k]>a[i]&&a[i]>a[j]){
					g[i][j]=(g[i][j]+f[i][k])%mod;
					cnt++;
				}
			}
			g[i][j]=(g[i][j]*inv[cnt])%mod;
			if(a[i]>a[j]){
				g[i][j]=(g[i][j]+1)%mod;
			}
			cnt=0;
			for(int k=i+1;k<=n;k++){	
				if(a[k]>a[j]&&a[j]>a[i]){
					f[i][j]=(f[i][j]+g[k][j])%mod;
					cnt++;
				}
			}
			f[i][j]=(f[i][j]*inv[cnt])%mod;
			if(a[i]<a[j]){
				g[i][j]=(g[i][j]+1)%mod;
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=(ans+f[i][j])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}