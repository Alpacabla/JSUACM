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
int pri[max_n>>1],num[max_n>>1];
bool vis[max_n];
int init()
{
	int i,j;
	int lim=max_n-5;
	int cnt=0;
	for(i=2;i<=lim;i++){
		if(!vis[i]) pri[cnt++]=i;
		for(j=0;j<cnt&&i*pri[j]<=lim;j++){
			vis[i*pri[j]]=true;
			if(i%pri[j]==0) break;
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	int cnt=init();
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>num[i];
	}
	ll ans=1;
	for(i=0;i<cnt;i++){
		ll k=(ll)pri[i];
		while(1){
			int flag=0;
			//cout<<"k"<<" "<<k<<endl;
			for(j=1;j<=n;j++){
				if(num[j]%k){
					//cout<<num[j]%k<<endl;
					flag++;
				}
				if(flag==2) break;
			}
			if(flag==2) break;
			k*=pri[i];
		}
		k/=pri[i];
		ans*=k;
	}
	cout<<ans<<endl;
	return 0;
}