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
const int max_n=5e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1];
char val[max_n<<1];
int tot;
inline void add(int a,int b,char v){
	to[++tot]=b;
	nxt[tot]=head[a];
	val[tot]=v;
	head[a]=tot;
	return ;
}
int siz[max_n],son[max_n],dep[max_n];
char sonval[max_n];
void dfs(int a,int fa)
{
	siz[a]=1;
	dep[a]=dep[fa]+1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			dfs(u,a);
			siz[a]+=siz[u];
			if(siz[u]>siz[son[a]]) son[a]=u,sonval[a]=val[i];
		}
	}
	return ;
}
map<int,int> mp;
int bb;
int ans[max_n];
int lcadep;
int tempans=0;
#define getbit(a) (((a)-('a')))
void calnode(int a,int fa,int pathval)
{
	tempans=max(tempans,(mp[pathval]+dep[a]-(lcadep<<1)));
	for(int i=0;i<26;i++){
		int b=(1<<i);
		//b[i]=1;
		if(mp.count(pathval^b)){
			tempans=max(tempans,(mp[pathval^b]+dep[a]-(lcadep<<1)));
		}
	}
	if(pathval^bb==0){
		tempans=max(tempans,dep[a]-lcadep);
	}
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			int b=1<<getbit(val[i]);
			//b[getbit(val[i])]=1;
			calnode(u,a,pathval^b);
		}
	}
	return ;
}
void addnode(int a,int fa,int pathval)
{
	if(mp[pathval]<dep[a]){
		mp[pathval]=dep[a];
	}
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			int b=1<<getbit(val[i]);
			//b[getbit(val[i])]=1;
			addnode(u,a,pathval^b);
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
	int b=0;
	if(son[a]){
		dsu(son[a],a,1);
		b=1<<getbit(sonval[a]);
		if(mp[b^bb]<dep[a]+1){
			mp[b^bb]=dep[a]+1;
		}
	}
	//b[getbit(sonval[a])]=1;
	// if(mp[b^]<dep[a]){
	// 	mp[pathval]=dep[a];
	// }
	bb^=(b);
	lcadep=dep[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa&&u!=son[a]){
			int bbb=1<<getbit(val[i]);
			calnode(u,a,bbb^bb);
			addnode(u,a,bbb^bb);
		}
	}
	ans[a]=tempans;
	if(!opt){
		mp.clear();
		bb=0;
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
	cin>>n;
	for(int i=2;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		add(a,i,b);
		add(i,a,b);
	}
	//cout<<'y'<<endl;
	dfs(1,0);
	dsu(1,0,1);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}