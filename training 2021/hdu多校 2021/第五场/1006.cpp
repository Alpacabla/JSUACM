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
const int max_n=1e6+5;
ll dp[max_n];
void init(int n)
{
	dp[1]=1;
	dp[2]=3;
	dp[3]=4;
	for(int i=4;i<=n;i++){
		int l=1;
		int b=1+(i/3)-1;
		int c=(b+i)/2;
		dp[i]=1+dp[b-l+1]+dp[c-b]+dp[i-c];
	}
	return ;
}
ll solve(int n)
{
	if(n<=1e6) return dp[n];
	else{
		int l=1;
		int b=1+(n/3)-1;
		int c=(b+n)/2;
		int len1=b,len2=c-b,len3=n-c;
		return solve(len1)+solve(len2)+solve(len3);
	}
}
int main()
{
	init(1e6);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int a;
		for(int i=1;i<=n;i++) scanf("%d",&a);
		printf("%lld\n",solve(n));
	}
	return 0;
}