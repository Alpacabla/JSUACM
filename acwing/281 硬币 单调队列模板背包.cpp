/*
link: https://www.acwing.com/problem/content/283/
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
int dp[max_n];
int v[max_n],c[max_n];
int main()
{
	int i,j;
	int n,m;
	while(1){
		scanf("%d%d",&n,&m);
		if(!n&&!m) break;
		memset(dp,0,sizeof(int)*(m+3));
		for(int i=1;i<=n;i++){
			scanf("%d",&v[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&c[i]);
		}
		dp[0]=true;
		for(int i=1;i<=n;i++){
			for(int o=0;o<v[i];o++){
				int k=-1;
				for(int j=o;j<=m;j+=v[i]){
					if(dp[j]) k=c[i];
					if(k>=0) dp[j]=true;
					k--;
				}
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++){
			ans+=dp[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}