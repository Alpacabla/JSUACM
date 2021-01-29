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
int dp[max_n];
int num[max_n];
vector<int> chu[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	int n,m;
	for(i=2;i<=100000;i++){
		int lim=sqrt((double)i);
		chu[i].push_back(1);
		for(j=2;j<=lim;j++){
			if(i%j==0){
				chu[i].push_back(i/j);
				chu[i].push_back(j);
			}
		}
	}
	cout<<"OK"<<endl;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>num[i];
		}
		if(n==1){
			cout<<"1"<<endl;
			continue;
		}
		for(i=1;i<=n;i++){
			dp[i]=1;
		}
		for(i=2;i<=n;i++){
			for(j=0;j<chu[i].size();j++){
				if(num[i]>num[chu[i][j]]&&dp[i]<dp[chu[i][j]]+1){
					dp[i]=dp[chu[i][j]]+1;
				}
			}
		}
		int ans=-1;
		for(i=1;i<=n;i++){
			ans=max(ans,dp[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}