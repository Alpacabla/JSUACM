/*
link: https://www.acwing.com/problem/content/93/
tags: 状压dp
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
const int max_n=(1<<20)+100;
int dp[20][max_n];
int dis[20][20];
void solve(const int s,const int sta)
{
	int t=sta;
	int ind=0,sub=1;
	while(t){
		if(t&1){
			dp[s][sta]=min(dp[s][sta],dis[s][ind]+dp[ind][sta-sub]);
		}
		ind++;
		sub<<=1;
		t>>=1;
	}
	return ;
}
inline void init(const int n)
{
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<n;i++){
		int sta=1;
		dp[i][sta]=dis[i][n-1];
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>dis[i][j];
		}
	}
	init(n);
	const int lim=(1<<n)-1;
	for(j=0;j<=lim;j++){
		for(i=0;i<n;i++){
			solve(i,j);
		}
	}
	cout<<dp[0][lim]<<endl;
	return 0;
}
