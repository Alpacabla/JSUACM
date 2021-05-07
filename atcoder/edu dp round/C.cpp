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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> dp[3];
	for(int i=0;i<3;i++) dp[i].resize(n+1);
	for(int i=1;i<=n;i++){
		int a[3];
		for(int j=0;j<3;j++){
			cin>>a[j];
		}
		for(int j=0;j<3;j++){
			for(int k=0;k<3;k++){
				if(j!=k){
					dp[j][i]=max(dp[j][i],dp[k][i-1]+a[j]);
				}
			}
		}
	}
	cout<<max(max(dp[0][n],dp[1][n]),dp[2][n])<<endl;
	return 0;
}