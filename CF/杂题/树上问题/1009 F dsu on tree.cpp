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
int head[max_n],to[max_n<<1],nxt[max_n<<1];
int tot;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int siz[max_n],son[max_n],dep[max_n];
void dfs(int a,int fa)
{
	siz[a]=1;
	dep[a]=dep[fa]+1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			dfs(u,a);
			siz[a]+=siz[u];
			if(siz[u]>siz[son[a]]) son[a]=u;
		}
	}
	return ;
}
map<int,int> mp;
int ans[max_n];
int max1=0,kk;
void addans(int a,int fa)
{
	int t=(++mp[dep[a]]);
	if(t>max1||(t==max1&&dep[a]<kk)) max1=t,kk=dep[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			addans(u,a);
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
	if(son[a]) dsu(son[a],a,1);
	int t=(++mp[dep[a]]);
	if(t>max1||(t==max1&&dep[a]<kk)) max1=t,kk=dep[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa&&u!=son[a]){
			addans(u,a);
		}
	}
	ans[a]=kk-dep[a];
	if(!opt){
		mp.clear();
		max1=0;
		kk=int_inf;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	scanf("%d",&n);
	//cin>>n;
	for(int i=2;i<=n;i++){
		int a,b;
		//cin>>a>>b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	dsu(1,0,1);
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}