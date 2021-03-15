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
int head[max_n],to[max_n<<1],nxt[max_n<<1];
int tot;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int v[max_n];
int siz[max_n];
int son[max_n];
int calsiz(int a,int fa)
{
	siz[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			int res=calsiz(u,a);
			if(siz[son[a]]<res) son[a]=u;
			siz[a]+=res;
		}
	}
	return siz[a];
}
const int max_m=3e6;
ll ans=0;
int trie[max_m][2];
int cnt[1000005][21][2];
int ind[max_m];
int now;
int lca;
inline void calcnt(int a,int val,int flag)
{
	for(int i=0;i<=20;i++){
		int k=(a>>i)&1;
		cnt[val][i][k]+=flag;
	}
	return ;
}
// int find(int val)
// {
// 	int x=0;
// 	for(int i=0;i<=20;i++){
// 		int k=(val>>i)&1;
// 		if(trie[x][k]){
// 			x=trie[x][k];
// 		}else{
// 			trie[x][k]=++now;
// 			x=now;
// 		}
// 	}
// 	return x;
// }
void caltrie(int val,int a)
{
	int x=val^lca;
	// int x=0;
	// for(int i=0;i<=20;i++){
	// 	int k=(((val>>i)&1)^((lca>>i)&1));
	// 	if(trie[x][k]){
	// 		x=trie[x][k];
	// 	}else{
	// 		x=0;
	// 		break;
	// 	}
	// }
	//if(ind[x]==0) return ;
	//else{
		for(int i=0;i<=20;i++){
			int k=(a>>i)&1;
			ans+=cnt[x][i][!k]*(1ll<<i);
		}
	//}
	return ;
}
void addnode(int val,int a,int flag)
{
	// if(flag==1){
	// 	int x=find(val);
	// 	ind[val]=x;
	// }else{
	// 	ind[val]=0;
	// }
	calcnt(a,val,flag);
	return ;
}
void calans(int a,int fa,int flag)
{
	switch(flag){
		case -1: addnode(v[a],a,flag); break;
		case 1: addnode(v[a],a,flag); break;
		case 2: caltrie(v[a],a); break;
	}
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			calans(u,a,flag);
		}
	}
}
void dfs(int a,int fa,bool opt)
{
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa&&u!=son[a]){
			dfs(u,a,0);
		}
	}
	if(son[a]) dfs(son[a],a,1);
	addnode(v[a],a,1);
	lca=v[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa&&u!=son[a]){
			calans(u,a,2);
			calans(u,a,1);
		}
	}
	if(!opt){
		addnode(v[a],a,-1);
		for(int i=head[a];i;i=nxt[i]){
			int &u=to[i];
			if(u!=fa){
				calans(u,a,-1);
			}
		}
		lca=0;
		memset(trie,0,sizeof(int)*((now<<1)+3));
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=2;i<=n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	calsiz(1,-1);
	dfs(1,-1,1);
	cout<<ans<<endl;
	return 0;
}