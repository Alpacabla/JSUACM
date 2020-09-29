/*
link: https://www.luogu.com.cn/problem/UVA10891
tags: seg dp   记忆化搜索
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
int dp[105][105];
int sum[105];
int f[2][105];
inline int getSe(int l,int r){
	if(l>r) return 0;
	return sum[r]-sum[l-1]-dp[l][r];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	while(cin>>n){
		if(!n) break;
		vector<int> num(n+1);
		sum[0]=0;
		for(i=1;i<=n;i++){
			cin>>num[i];
			sum[i]=sum[i-1]+num[i];
		}
		memset(f[0],-0x3f3f,sizeof(int)*(n+1));
		memset(f[1],-0x3f3f,sizeof(int)*(n+1));
		for(i=1;i<=n;i++){
			memset(dp[i],-0x3f3f,sizeof(int)*(n+1));
		}
		for(i=0;i<n;i++){
			for(j=1;j<=n-i;j++){
				int res=max(num[j]+getSe(j+1,j+i),num[j]+f[0][j+1]);
				f[0][j]=res;
				res=max(num[j+i]+getSe(j,j+i-1),num[j+i]+f[1][j]);
				f[1][j]=res;
				dp[j][j+i]=max(f[0][j],f[1][j]);
			}
		}
		cout<<dp[1][n]-getSe(1,n)<<endl;
	}
	return 0;
}
