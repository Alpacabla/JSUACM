/*
link: https://www.luogu.com.cn/problem/UVA10859
tags: tree dp 小技巧
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
const int max_n=1e3+5;
vector<int> edge[max_n];
bool vis[max_n];
const int M=2e3;	//维护两个最小值时用min1=M*x1+x2来做到同时维护
					//x1为优先维护，x2为第二维护，M为一个超过x2值域宽度的取值常数
					//同时注意不要算数溢出了，所以够用就行，不能盲目取大值
int min1,cnt;
int dp[max_n][2];
void dfs(int a)
{
	vis[a]=true;
	bool flag=true;
	dp[a][1]=M;
	for(int i=0;i<edge[a].size();i++){
		int &u=edge[a][i];
		if(!vis[u]){
			cnt++;
			flag=false;
			dfs(u);
			int res;
			if(dp[u][1]<dp[u][0]+1){
				res=dp[u][1];
			}else{
				res=dp[u][0]+1;
			}
			dp[a][1]+=res;
			dp[a][0]+=dp[u][1]+1;
		}
	}
	//if(flag) dp[a][1]=M;
	min1=min(dp[a][0],dp[a][1]);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		memset(vis,0,sizeof(bool)*(n));
		memset(dp,0,sizeof(int)*((n<<1)+5));
		for(i=0;i<n;i++){
			edge[i].clear();
		}
		for(i=0;i<m;i++){
			int a,b;
			cin>>a>>b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		int ans1=0,ans2=0,ans3=0;
		for(i=0;i<n;i++){
			if(!vis[i]){
				min1=int_inf;
				cnt=0;
				dfs(i);
				if(min1==int_inf) continue;
				ans1+=min1/M;
				ans2+=min1%M;
				ans3+=(cnt-(min1%M));
			}
		}
		cout<<ans1<<" "<<ans3<<" "<<ans2<<endl;
	}
	return 0;
}
