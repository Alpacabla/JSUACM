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
int dp[max_n][2];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1];
		if(a[i]>=dp[i-1][0]){
			dp[i][1]=dp[i][0];
			dp[i][0]=a[i];
		}else{
			if(a[i]>dp[i-1][1]){
				dp[i][1]=a[i];
			}
		}
	}
	int q;
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		cout<<dp[x][1]<<endl;
	}
	return 0;
}