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
int fa[24][max_n];
int dep[max_n];
int log_2[max_n];
int head[max_n];
int nxt[max_n*2];
int to[max_n*2];
int cnt;
const int max_m=5e6;
int tot,ls[max_m],rs[max_m],sz[max_m],val[max_m],root[max_n];
inline int newnode(){
	sz[++tot]=1;
	return tot;
}
int build(int l,int r,const int v)
{
	int now=newnode();
	if(l==r){
		return now;
	}
	int mid=(l+r)>>1;
	if(v<=mid) ls[now]=build(l,mid,v);
	else rs[now]=build(mid+1,r,v);
	return now;
}
int insert(int now,int l,int r,const int v)
{
	if(!now){
		now=build(l,r,v);
		return now;
	}
    sz[now]++;
	if(l==r){
		return now;
	}
	int mid=(l+r)>>1;
	if(v<=mid) ls[now]=insert(ls[now],l,mid,v);
	else rs[now]=insert(rs[now],mid+1,r,v);
	return now;
}
int merge(const int a,const int b)
{
	if(!a||!b) return a?a:b;
	sz[a]+=sz[b];
	ls[a]=merge(ls[a],ls[b]);
	rs[a]=merge(rs[a],rs[b]);
	return a;
}
inline void add_edge(int a,int b){
	nxt[++cnt]=head[a];
	head[a]=cnt;
	to[cnt]=b;
	return ;
}
void creat_tree(int root,int father)
{
	dep[root]=dep[father]+1;
	int i=0;
	while(i<log_2[dep[root]]){
		fa[i+1][root]=fa[i][fa[i][root]];
		i++;
	}
	for(i=head[root];i;i=nxt[i]){
		int& vertex=to[i];
		if(vertex!=father){
			fa[0][vertex]=root;
			creat_tree(vertex,root);
		}
	}
	return ;
}
struct node{
	int l,r,tr,ind;
};
int tem[max_n];
int ans[max_n];
vector<node> vir[max_n];
int check(int now,int l,int r,int l1,int r1)
{
	if(l>r1||r<l1||!now){
		return 0;
	}
	if(l>=l1&&r<=r1){
		return sz[now];
	}
	int mid=(l+r)>>1;
	return check(ls[now],l,mid,l1,r1)+check(rs[now],mid+1,r,l1,r1);
}
void dfs(int a,int fa)
{
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			dfs(u,a);
		}
	}
	root[a]=build(1,1e9,tem[a]);
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			root[a]=merge(root[a],root[u]);
		}
	}
	for(int i=0;i<vir[a].size();i++){
		ans[vir[a][i].ind]=check(root[a],1,1e9,vir[a][i].l,vir[a][i].r);
	}
}
int main()
{
	int n;
	const int root=1;
	int i,j;
	int a,b;
	scanf("%d",&n);
	int x=1;
	log_2[0]=-1;
	for(i=1;i<=n;i++){
		if(x!=i) log_2[i]=log_2[i-1];
		else  x<<=1,log_2[i]=log_2[i-1]+1;
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add_edge(a,b);
		add_edge(b,a);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",tem+i);
	}
	fa[0][root]=0;
	dep[0]=-1;
	creat_tree(root,0);
	int m;
	scanf("%d",&m);
	vector<node> q(m+1);
	for(int i=1;i<=m;i++){
		int tr,l,r;
		scanf("%d%d%d",&tr,&l,&r);
		q[i]=(node){l,r,tr,i};
	}
	for(int i=1;i<=m;i++) {
        if(q[i].r<tem[q[i].tr] || q[i].l>tem[q[i].tr]) continue;
        int pos=q[i].tr;
        int lim=log_2[dep[pos]];

        for(int j=lim;j>=0;j--){
        	int f=fa[j][pos];
        	if(f==0) continue;
        	if(tem[f]<=q[i].r){
        		pos=f;
        	}
        }
		vir[pos].push_back(q[i]);
	}
	dfs(root,0);
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}