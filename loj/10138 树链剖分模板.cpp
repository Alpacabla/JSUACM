/*
link: https://loj.ac/p/10138
tags: 重链剖分，把树转成序列后维护区间和以及单点修改。
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
int head[max_n],to[max_n<<1],nxt[max_n<<1];
int tot;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int siz[max_n],dep[max_n],son[max_n],pa[max_n],top[max_n];
int dfn[max_n],id[max_n];
void dfs1(int a,int fa)
{
	siz[a]=1;
	pa[a]=fa;
	dep[a]=dep[fa]+1;
	int max1=-1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			dfs1(u,a);
			if(siz[u]>max1){
				max1=siz[u];
				son[a]=u;
			}
			siz[a]+=siz[u];
		}
	}
	return ;
}
int totid;
void dfs2(int a,int topa)
{
	dfn[a]=++totid;
	top[a]=topa;
	if(son[a]!=0) dfs2(son[a],topa);
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa[a]&&u!=son[a]){
			dfs2(u,u);
		}
	}
	return ;
}
void init()
{
	dfs1(1,0);
	dfs2(1,1);
}
int val[max_n];
int sum[max_n<<2],max1[max_n<<2];
int _index[max_n];
#define maintain(a) ((sum[a]=sum[to_l(a)]+sum[to_r(a)],max1[a]=max(max1[to_r(a)],max1[to_l(a)])))
void build(int l,int r,int ind)
{
	max1[ind]=-int_inf;
	if(l==r){
		sum[ind]=max1[ind]=val[l];
		_index[l]=ind;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,to_l(ind));
	build(mid+1,r,to_r(ind));
	maintain(ind);
	return ;
}
int ans;
void query(int l1,int r1,int l,int r,int ind,bool flag)
{
	if(l1>r||r1<l) return ;
	if(l>=l1&&r<=r1){
		if(flag) ans=max(ans,max1[ind]);
		else ans+=sum[ind];
		return ;
	}
	int mid=(l+r)>>1;
	query(l1,r1,l,mid,to_l(ind),flag);
	query(l1,r1,mid+1,r,to_r(ind),flag);
	return ;
}
void change(int a,int ind)
{
	sum[ind]=max1[ind]=a;
	ind>>=1;
	while(ind){
		maintain(ind);
		ind>>=1;
	}
	return ;
}
void solve(int a,int b,bool flag,const int n){
	if(flag) ans=-int_inf;
	else ans=0;
	while(top[a]!=top[b]){
		if(dep[top[a]]<dep[top[b]]){
			swap(a,b);
		}
		query(dfn[top[a]],dfn[a],1,n,1,flag);
		//要记住修改的区间是从 top 到 a，因为上面节点的 dfn 序要小
		a=pa[top[a]];
	}
	if(dep[a]>dep[b]){
		swap(a,b);
	}
	query(dfn[a],dfn[b],1,n,1,flag);
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
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	init();
	for(int i=1;i<=n;i++){
		int v;
		cin>>v;
		val[dfn[i]]=v;
	}
	build(1,n,1);
	int m;
	cin>>m;
	while(m--){
		string s;
		int a,b;
		cin>>s>>a>>b;
		if(s[1]=='M'){
			solve(a,b,1,n);
			cout<<ans<<endl;
		}else{
			if(s[1]=='S'){
				solve(a,b,0,n);
				cout<<ans<<endl;
			}else{
				change(b,_index[dfn[a]]);
			}
		}
	}
	return 0;
}