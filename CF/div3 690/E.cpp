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
ll c[max_n][105];
ll pro[max_n];
ll inv_pro[max_n];
ll qpow(ll a,ll b)
{
	ll res=1;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
void init()
{
	int lim=2e5;
	pro[0]=1;
	for(int i=1;i<=lim;i++){
		pro[i]=(pro[i-1]*i)%mod;
	}
	inv_pro[0]=1;
	for(int i=1;i<=lim;i++){
		inv_pro[i]=qpow(pro[i],mod-2);
	}
	for(int i=1;i<=lim;i++){
		for(int j=0;j<=100&&j<=i;j++){
			c[i][j]=pro[i]*inv_pro[j]%mod*inv_pro[i-j]%mod;
		}
	}
	c[0][0]=1;
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	init();
	cin>>t;
	while(t--){
		int n,k,m;
		cin>>n>>m>>k;
		vector<int> book(n+1),sum(n+1),num(n+1);
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			book[a]++;
		}
		int ind=1;
		for(int i=1;i<=n;i++){
			while(book[i]){
				num[ind++]=i;
				book[i]--;
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			int min1=num[i]-k;
			int k=(int)(lower_bound(num.begin()+1,num.end(),min1)-num.begin());
			if(i-k+1>=m){
				int cnt=i-k+1;
				ans=(ans+c[cnt-1][m-1])%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}