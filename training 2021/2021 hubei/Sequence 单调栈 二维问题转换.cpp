/*
link: https://codeforces.com/gym/103104/problem/I
tags: 首先是转换为二维问题，变成求正方形个数
	  接着想到使用单调栈
	  再接着要推出奇怪的计数公式
	  down
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=5e3+5;
bool vis[max_n][max_n];
int top[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		vis[a][b]=true;
	}
	for(int i=1;i<=n;i++){
		top[i]=1;
		vis[i][n+1]=true;
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			while(!vis[j][top[j]]){
				top[j]++;
			}
		}
		stack<int> sta;
		sta.push(0);
		top[0]=-1;
		for(int j=1;j<=n;j++){
			while(top[sta.top()]>top[j]){
				int ind=sta.top();
				sta.pop();
				ans+=((j-ind)*1ll*(ind-sta.top()))*(top[ind]-i);
			}
			sta.push(j);
		}
		int vvv=n+1;
		while(sta.size()>1){
			int ind=sta.top();
			sta.pop();
			ans+=((vvv-ind)*1ll*(ind-sta.top()))*(top[ind]-i);
		}
		for(int j=1;j<=n;j++){
			if(top[j]==i&&vis[j][i]) top[j]++;
		}
	}
	cout<<ans<<endl;
	return 0;
}