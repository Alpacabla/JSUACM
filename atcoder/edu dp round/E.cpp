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
	int n,W;
	cin>>n>>W;
	vector<int> dp(n*1e3+5,int_inf);
	int sum=0;
	dp[0]=0;
	for(int i=1;i<=n;i++){
		int w,v;
		cin>>w>>v;
		sum+=v;
		for(int j=sum;j>=v;j--){
			dp[j]=min(dp[j],dp[j-v]+w);
		}
	}
	int ans=0;
	for(int i=sum;i>=0;i--){
		if(dp[i]<=W) {ans=i;break;}
	}
	cout<<ans<<endl;
	return 0;
}