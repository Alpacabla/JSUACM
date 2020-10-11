/*
link: https://www.acwing.com/problem/content/280/
tags: 背包
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
const int max_n=1e4+5;
int dp[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	vector<int> num(n+1);
	for(i=1;i<=n;i++){
		cin>>num[i];
	}
	dp[0]=1;
	for(i=1;i<=n;i++){
		for(j=m;j>=num[i];j--){
			dp[j]+=dp[j-num[i]];
		}
	}
	cout<<dp[m]<<endl;
	return 0;
}
