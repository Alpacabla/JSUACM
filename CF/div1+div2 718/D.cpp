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
ll dp[505][505][11];
int u[505][505],d[505][505],l[505][505],r[505][505];
//void dfs(int x,int y,int len)
//{
//	if(len<=0) return ;
//	if(u[x][y]){
//		dfs(x-1,y,len-1);
//	}
//	if(d[x][y]){
//		dfs(x+1,y,len-1);
//	}
//	if(l[x][y]){
//		dfs(x,y-1,len-1);
//	}
//	if(r[x][y]){
//		dfs(x,y+1,len-1);
//	}
//}
int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if(k%2==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("-1 ");
			}
			printf("\n");
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			int v;
			scanf("%d",&v);
			r[i][j]=l[i][j+1]=v;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			int v;
			scanf("%d",&v);
			d[i][j]=u[i+1][j]=v;
		}
	}
	
//	for(int len=1;len<=k/2;len++){
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=m;j++){
//				dfs(i,j,len);
//			}
//		}
//	}
	
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			dp[i][j][0]=0;
		}
	}
	
	for(int len=1;len<=k/2;len++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int &x=i,&y=j;
				if(u[x][y]){
					dp[x][y][len]=min(dp[x][y][len],dp[x-1][y][len-1]+2*u[x][y]);
				}
				if(d[x][y]){
					dp[x][y][len]=min(dp[x][y][len],dp[x+1][y][len-1]+2*d[x][y]);
				}
				if(l[x][y]){
					dp[x][y][len]=min(dp[x][y][len],dp[x][y-1][len-1]+2*l[x][y]);
				}
				if(r[x][y]){
					dp[x][y][len]=min(dp[x][y][len],dp[x][y+1][len-1]+2*r[x][y]);
				}
			}
		}
	}
	int z=k/2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%lld ",dp[i][j][z]);
		}
		printf("\n");
	}
	return 0;
}
