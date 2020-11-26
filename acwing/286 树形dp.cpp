/*
link: https://www.acwing.com/problem/content/288/
tags: 树形dp
	  有个更好的写法下次看
	  https://www.acwing.com/solution/content/5321/
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
int v[1000],dp[1000][1000],size1[1000];
vector<int> son[1000];
int dfs(int a)
{
	size1[a]=1;
	for(int i=0;i<son[a].size();i++){
		size1[a]+=dfs(son[a][i]);
	}
	int cnt=1;
	if(son[a].size()) cnt=size1[son[a][0]];
	else{
		dp[a][1]=v[a];
		return size1[a];
	}
	for(int i=0;i<son[a].size();i++){
		int &u=son[a][i];
		int dp1[1000]={0};
		for(int j=0;j<=cnt;j++){
			for(int k=0;k<=size1[u];k++){
				dp1[j+k]=max(dp1[j+k],dp[u][k]+dp[a][j]);
			}
		}
		cnt+=size1[u];
		for(int j=0;j<=cnt;j++) dp[a][j]=dp1[j];
	}
	for(int i=cnt;i>=0;i--){
		if(dp[a][i]||i==0) dp[a][i+1]=dp[a][i]+v[a];
	}
	return size1[a];
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a,b;
		cin>>a>>b;
		son[a].push_back(i);
		v[i]=b; 
	}
	dfs(0);
	cout<<dp[0][m+1]<<endl;
}