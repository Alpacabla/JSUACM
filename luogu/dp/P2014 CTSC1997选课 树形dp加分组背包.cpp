/*
link: https://www.luogu.com.cn/problem/P2014
tags: 树形dp+分组背包 没什么变化，但是要注意虚拟的根节点也要随之拥有状态和容量
	  最后答案要多选一个就行了
	  状态转移中初值是关键 j从i+1开始因为自己的根一定要选
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
int v[305],pa[305];
int dp[305][305];
int t[305];
int du[305];
bool vis[305];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>pa[i];
		cin>>dp[i][1];
		du[pa[i]]++;
	}
	dp[0][1]=1;
	stack<int> sta;
	for(int i=1;i<=n;i++){
		if(!du[i]){
			sta.push(i);
		}
	}
	while(sta.size()){
		int a=sta.top();
		if(a==0) break;
		sta.pop();
		int fa=pa[a];
		for(int i=0;i<305;i++){
			t[i]=dp[fa][i];
		}

		for(int i=0;i<305;i++){
			for(int j=i+1;j<305;j++){
				dp[fa][j]=max(dp[fa][j],t[j-i]+dp[a][i]);
			}
		}
		du[fa]--;
		if(!du[fa]){
			sta.push(fa);
		}
	}
	cout<<dp[0][m+1]-1<<endl;
	return 0;
}