// Problem: D. Priority Queue
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int mod=998244353;
int dp[505][505];
//因为队列中就算没有元素也可以执行-操作,所以比大的数的数量没有意义
//并且要注意，为了无重枚举，需要做位置判断
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<bool> sta(n+1);
	vector<int> x(n+1);
	for(int i=1;i<=n;i++){
		char s;
		cin>>s;
		if(s=='-'){
			sta[i]=false;
		}else{
			sta[i]=true;
			cin>>x[i];
		}
	}
	
	int ans=0;
	for(int i=1;i<=n;i++){
		if(!sta[i]) continue;
		vector<vector<int> >dp(n+1,vector<int>(n+1));
		dp[0][0]=1;
		for(int j=1;j<=n;j++){
			if(i==j){
				for(int k=0;k<dp.size();k++){
					dp[j][k]=dp[j-1][k];
				}
				continue;
			}
			
			if(sta[j]){
				if(x[j]<x[i]||(x[j]==x[i]&&j<i)){
					dp[j][0]+=dp[j-1][0];
					for(int k=1;k<(int)dp.size();k++){
						dp[j][k]=(dp[j-1][k-1]+dp[j-1][k])%mod;
					}
				}else{
					for(int k=0;k<(int)dp.size();k++){
						dp[j][k]=(dp[j-1][k]*2)%mod;
					}
				}
			}else{
				if(j<i){
					dp[j][0]=(dp[j-1][1]+(dp[j-1][0]<<1)%mod)%mod;
				}else{
					dp[j][0]=(dp[j-1][1]+(dp[j-1][0]))%mod;
				}
				
				for(int k=1;k<(int)dp.size()-1;k++){
					dp[j][k]+=(dp[j-1][k]+dp[j-1][k+1])%mod;
				}
			}
		}
		for(int k=0;k<dp.size();k++){
			ans+=(1ll*x[i]*dp[n][k])%mod;
			ans%=mod;
		}
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
	
	return 0;
}