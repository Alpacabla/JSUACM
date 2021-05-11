// Problem: D. Diverse Garland
// Contest: Codeforces - Codeforces Round #535 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1108/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> dp[3],last[3];
	for(int i=0;i<3;i++) dp[i].resize(n+1,int_inf),last[i].resize(n+1,-1);
	//s=" "+s;
	vector<int> v(150);
	string sval="RGB";
	v['R']=0;
	v['G']=1;
	v['B']=2;
	dp[0][0]=1;
	dp[2][0]=1;
	dp[1][0]=1;
	dp[v[s[0]]][0]=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(j!=k){
					if(dp[j][i]>dp[k][i-1]){
						dp[j][i]=dp[k][i-1];
						last[j][i]=k;
					}
					//dp[j][i]=min(dp[j][i],dp[k][i-1]);
				}
			}
		}
		for(int j=0;j<3;j++){
			if(j==v[s[i]]) continue;
			dp[j][i]++;
		}
	}
	int ans=int_inf;
	for(int i=0;i<3;i++){
		ans=min(ans,dp[i][n-1]);
	}
	int ind=-1;
	for(int i=0;i<3;i++){
		if(ans==dp[i][n-1]) ind=i;
	}
	cout<<ans<<endl;
	string out="";
	while(~ind){
		out+=sval[ind];
		ind=last[ind][--n];
	}
	reverse(out.begin(),out.end());
	cout<<out<<endl;
	return 0;
}