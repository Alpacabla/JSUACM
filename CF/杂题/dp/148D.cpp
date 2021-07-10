// Problem: D. Bag of mice
// Contest: Codeforces - Codeforces Round #105 (Div. 2)
// URL: https://codeforces.com/problemset/problem/148/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int a,b;
	cin>>a>>b;
	vector<vector<double> >dp(a+1,vector<double>(b+1));
	for(int i=0;i<=b;i++){
		dp[0][i]=0;
	}
	for(int i=1;i<=a;i++){
		dp[i][0]=1; 
	}
	for(int i=1;i<=a;i++){
		for(int j=1;j<=b;j++){
			dp[i][j]+=1.0*i/(i+j);
			if(j>=2){
				dp[i][j]+=1.0*j/(i+j)*(j-1)/(i+j-1)*i/(i+j-2)*dp[i-1][j-2];
			}
			if(j>=3){
				dp[i][j]+=1.0*j/(i+j)*(j-1)/(i+j-1)*(j-2)/(i+j-2)*dp[i][j-3];
			}
		}
	}
	printf("%.10lf\n",dp[a][b]);
	return 0;
}