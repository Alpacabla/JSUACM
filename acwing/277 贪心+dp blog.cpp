/*
link: https://www.acwing.com/problem/content/279/
tags: 这道题启发我们，有时可以通过额外的算法确定DP状态的计算顺序，
      有时可以在状态空间中运用等效手法对状态进行缩放。在本题中，我们就利用贪心策略，
      在DP前对N个孩子执行排序，使他们获得的饼干数单调递减。我们还利用相对大小的不不变性，
      把第i+1个孩子获得的饼干数先缩放到1，再考虑i前面有几个孩子获得的饼干数量相等，
      使需要计算的问题得到了极大的简化，容易进行维护、转移。
      //转自评论区：asd少年 
      贪心 + dp + dfs找答案
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
struct node{
    int a,ind;
    bool operator < (const node b) const {
        return a>b.a;
    }
}aa[35];
int ans[35];
int sum[35];
int dp[35][5005];
int last[35][5005][2];
void dfs(int x,int y)
{
	if(y==0){
		return ;
	}
	int a=last[x][y][0],b=last[x][y][1];
	dfs(a,b);
	if(a==x){
		for(int i=1;i<=a;i++){
			ans[aa[i].ind]+=1;
		}
	}else{
		for(int i=a+1;i<=x;i++){
			ans[aa[i].ind]=1;
		}
	}
	return ;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i].a;
		aa[i].ind=i;
	}
	sort(aa+1,aa+1+n);
	for(int i=1;i<=n;i++){
	    sum[i]=sum[i-1]+aa[i].a;
	}
	memset(dp,0x3f3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][0]=0;
		for(int j=i;j<=m;j++){
			dp[i][j]=dp[i][j-i];
			last[i][j][0]=i;
			last[i][j][1]=j-i;
			for(int k=1;k<=i;k++){
				if(dp[i][j]>dp[i-k][j-k]+(sum[i]-sum[i-k])*(i-k)){
					dp[i][j]=dp[i-k][j-k]+(sum[i]-sum[i-k])*(i-k);
					last[i][j][0]=i-k;
					last[i][j][1]=j-k;
				}
			}
		}
	}
	dfs(n,m);
	cout<<dp[n][m]<<endl;
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
