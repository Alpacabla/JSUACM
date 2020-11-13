/*
link: https://www.acwing.com/problem/content/166/
tags: bitset
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
const int max_n=3e4+5;
int head[max_n],to[max_n],nxt[max_n],cnt;
bitset<max_n> bit[max_n];
inline void add(int a,int b){
	to[++cnt]=b;
	nxt[cnt]=head[a];
	head[a]=cnt;
	return ;
}
int ans[max_n],du[max_n];
bool vis[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		add(y,x);
		du[x]++;
	}
	for(int i=1;i<=n;i++){
		bit[i][i]=1;
	}
	stack<int>sta;
	while(!sta.empty()) sta.pop();
	for(int i=1;i<=n;i++){
		ans[i]=1;
		if(du[i]==0){
			sta.push(i);
		}
	}
	while(!sta.empty()){
		int x=sta.top();
		sta.pop();
		for(int i=head[x];i;i=nxt[i]){
			du[to[i]]--;
			bit[to[i]]|=bit[x];
			if(du[to[i]]==0){
				sta.push(to[i]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<bit[i].count()<<endl;
	}
	return 0;
}