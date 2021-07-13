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
double dp[2][(1<<15)];
int presta[16],val[16];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k,n;
	cin>>k>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>val[i];
		while(1){
			cin>>a;
			if(a==0) break;
			presta[i]|=(1<<(a-1));
		}
	}
	int kk=0;
	for(int i=k;i>=1;i--){
		for(int j=0;j<(1<<n);j++) dp[kk][j]=0;
		for(int o=0;o<(1<<n);o++){
			if(__builtin_popcount(o)>(i-1)){
				continue;
			}
			for(int j=1;j<=n;j++){
				if((o&presta[j])==presta[j]){
					dp[kk][o]+=max(dp[!kk][o],dp[!kk][(o|(1<<(j-1)))]+val[j]);
				}else{
					dp[kk][o]+=dp[!kk][o];
				}
			}
		}
		for(int j=0;j<(1<<n);j++) dp[kk][j]/=n;
		kk=!kk;
	}
	cout<<fixed<<setprecision(6)<<dp[!kk][0]<<endl;
	return 0;
}