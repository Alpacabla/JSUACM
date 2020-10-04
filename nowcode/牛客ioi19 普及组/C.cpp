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
const int max_n=1e6+5;
int dfn[max_n],low[max_n];
int head[max_n],nxt[max_n<<2],to[max_n<<2];
bool vis_e[max_n<<2];
int cnt=1;
bool vis[max_n];
inline void add(int a,int b)
{
	to[++cnt]=b;
	nxt[cnt]=head[a];
	head[a]=cnt;
	return ;
}
int ans=0;
int now=0;
bool tarjan(int a,int fa,const int k)
{
	vis[a]=true;
	dfn[a]=low[a]=++now;
	bool flag=false;
	//cout<<a<<endl;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		bool temp=false;
		if(!vis[u]){
			temp=tarjan(u,a,k);
			if(!flag) flag=temp;
			low[a]=min(low[a],low[u]);
		}else{
			low[a]=min(low[a],dfn[u]);
		}
		if(a<=k&&(low[u]<dfn[a]||dfn[u]<=dfn[a])&&u!=fa&&!vis_e[i]){
			//cout<<a<<" "<<u<<endl;
			//cout<<temp<<endl;
			if(!temp) {ans++;vis_e[i]=true;vis_e[i^1]=true;}
		}
	}
	if(!flag) return a<=k;
	else return flag;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m,k;
	cin>>n>>m>>k;
	for(i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	for(i=1;i<=n;i++){
		if(!vis[i]){
			tarjan(i,-1,k);
		}
	}
	//tarjan(2,-1,k);
	cout<<ans<<endl;
	return 0;
}
