/*
link: 
tags: 
*/
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
ll qpow(ll a,int b)
{
	ll ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll x[1005],inv_x[1005];
ll c[1005][1005];
void init()
{
	int n=1e3;
	x[0]=1;
	for(int i=1;i<=n;i++){
		x[i]=x[i-1]*i%mod;
		inv_x[i]=qpow(x[i],mod-2);
	}
	inv_x[0]=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=0;j--){
			c[i][j]=x[i]*inv_x[j]%mod*inv_x[i-j]%mod;
		}
	}
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
		int n,k;
		cin>>n>>k;
		vector<int> num(n+1);
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		sort(num.begin()+1,num.end(),[](const int a,const int b)-> bool {
			return a>b;
		});
		for(i=k-1;i>=1&&num[i]==num[i+1];i--);
		int cnt1=k-i;
		int cnt2=0;
		for(int i=1;i<=n;i++){
			if(num[i]==num[k]){
				cnt2++;
			}
		}
		cout<<c[cnt2][cnt1]<<endl;
	}

	return 0;
}