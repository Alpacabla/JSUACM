/*
link: https://codeforces.com/contest/741/problem/D
tags: dus on tree 的老板子题，但是这题用到了一个 trick
	  就是固定根的两节点的树上 XOR 路径权值可以用他们到
	  根的 XOR 路径权值异或得来，有了这个之后其他都是简单了。
	  老是忘了
	  ORZ，不然根本保存不了一颗重子树的信息。
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
const int max_n=5e5+5;
#pragma GCC optimize(2)
int head[max_n],to[max_n<<1],nxt[max_n<<1],val[max_n<<1];
int tot;
inline void add(int a,int b,char v){
	to[++tot]=b;
	nxt[tot]=head[a];
	val[tot]=(1<<(v-'a'));
	head[a]=tot;
	return ;
}
int siz[max_n],son[max_n],dep[max_n],pathval[max_n];
void dfs(int a,int fa,int pval)
{
	siz[a]=1;
	dep[a]=dep[fa]+1;
	pathval[a]=pval;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			dfs(u,a,pval^val[i]);
			siz[a]+=siz[u];
			if(siz[u]>siz[son[a]]) son[a]=u;
		}
	}
	return ;
}
int initcal[23];
void init()
{
	initcal[0]=0;
	for(int i=1;i<=22;i++){
		initcal[i]=(1<<(i-1));
	}
	return ;
}
int vis[1<<22];
int ans[max_n];
int lcadep;
int tempans=0;
inline void calans(int val,int depth)
{
	for(int i=0;i<=22;i++){
		int k=val^initcal[i];
		if(vis[k]){
			tempans=max(tempans,vis[k]+depth-(lcadep<<1));
		}
	}
	return ;
}
void calnode(int a,int fa)
{
	calans(pathval[a],dep[a]);
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			calnode(u,a);
		}
	}
	return ;
}
void addnode(int a,int fa,bool flag)
{
	if(flag) vis[pathval[a]]=max(vis[pathval[a]],dep[a]);
	else vis[pathval[a]]=0;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			addnode(u,a,flag);
		}
	}
	return ;
}
void dsu(int a,int fa,bool opt)
{
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa&&u!=son[a]){
			dsu(u,a,0);
		}
	}
	if(son[a]){
		dsu(son[a],a,1);
	}

	lcadep=dep[a];
	calans(pathval[a],dep[a]);
	vis[pathval[a]]=max(dep[a],vis[pathval[a]]);

	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa&&u!=son[a]){
			calnode(u,a);
			addnode(u,a,1);
			tempans=max(tempans,ans[u]);
		}
	}
	ans[a]=tempans;
	if(!opt){
		vis[pathval[a]]=0;
		for(int i=head[a];i;i=nxt[i]){
			int &u=to[i];
			if(u!=fa){
				addnode(u,a,0);
			}
		}
		lcadep=0;
		tempans=0;
	}

	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	init();
	cin>>n;
	for(int i=2;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		add(a,i,b);
		add(i,a,b);
	}
	dfs(1,0,0);
	dsu(1,0,1);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}