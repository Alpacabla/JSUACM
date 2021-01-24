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
int pri[max_n];
bool vis[max_n];
int cnt=0;
inline void init()
{
	int n=1e5;
	for(int i=2;i<=n;i++){
		if(!vis[i]) pri[cnt++]=i;
		for(int j=0;j<cnt&&i*pri[j]<=n;j++){
			vis[i*pri[j]]=true;
			if(i%pri[j]==0) break;
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
		ll n;
		cin>>n;
		ll a,b;
		int k=int(lower_bound(pri,pri+cnt,1+n)-pri);
		a=pri[k];
		k=int(lower_bound(pri,pri+cnt,a+n)-pri);
		b=pri[k];
		cout<<a*b<<endl;
	}
	return 0;
}