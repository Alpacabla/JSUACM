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
vector<int> e[1005];
bool vis[1005];
void dfs(int a)
{
	if(vis[a]) return ;
	vis[a]=true;
	for(int i=0;i<e[a].size();i++){
		dfs(e[a][i]);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	vector<int> cnt(n+1);
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
		cnt[a]++;
		cnt[b]++;
	}
	dfs(1);
	bool flag=true;
	for(int i=1;i<=n&&flag;i++){
		flag=vis[i];
	}
	for(int i=1;i<=n&&flag;i++){
		if(cnt[i]%2==1) flag=false; 
	}
	if(flag) cout<<"1"<<endl;
	else cout<<"0"<<endl;
	return 0;
}