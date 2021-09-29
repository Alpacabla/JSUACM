// Problem: F. Array Stabilization (AND version)
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
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
	cin>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int> a(n),vis(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		bool flagflag=true;
		int ans=0;
		for(int i=0;i<n;i++){
			if(!vis[i]){
				int j=i;
				vector<int> val(1,0);
				int last=0;
				bool flag=false;
				while(!vis[j]){
					if(!a[j]) flag=true; 
					val.push_back(a[j]);
					vis[j]=true;
					j+=d;
					j%=n;
				}
				if(!flag){
					flagflag=false;break;
				}else{
					vector<int> dp(val.size());
					int k=0;
					int vv=0;
					for(int i=1;i<val.size();i++){
						if(!val[i]){ 
							dp[i]=0;
							if(vv==0){
								vv=dp[i-1];
							}
						}
						else dp[i]=dp[i-1]+1;
						k=max(k,dp[i]);
					}
					if(val[1]==1&&val[val.size()-1]==1){
						k=max(k,dp[val.size()-1]+vv);
					}
					ans=max(ans,k);
				}
			}
		}
		if(!flagflag) ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}