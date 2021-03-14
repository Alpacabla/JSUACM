/*
link: https://www.luogu.com.cn/problem/P3806
tags: 点分治最重要的是复杂度证明，最好要找重心，接着就是细节一定不要写错，因为模块很多，虽然都很简单。
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
const int max_n=1e4+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],val[max_n<<1];
int tot;
inline void add(int a,int b,int v){
	to[++tot]=b;
	val[tot]=v;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
bool vis[max_n];
int siz[max_n];
int calsize(int a,int fa)
{
	int weight=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			weight+=calsize(u,a);
		}
	}
	siz[a]=weight;
	return siz[a];
}
int min1;
int cen;
int all;
void findcen(int a,int fa)
{
	int max1=all-siz[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			findcen(u,a);
			max1=max(max1,siz[u]);
		}
	}
	if(max1<min1){
		min1=max1;
		cen=a;
	}
	return ;
}
const int max_m=1e7+5;
bool sum[max_m];
queue<int> q,t;
vector<int> query;
vector<bool> ans;
void calval(int a,int fa,int v)
{
	if(v>1e7) return ;
	q.push(v);
	t.push(v);
	for(int i=1;i<query.size();i++){
		if(!ans[i]){
			if(query[i]-v>=0){
				if(sum[query[i]-v]){
					ans[i]=true;
				}
			}
		}
	}
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			calval(u,a,v+val[i]);
		}
	}
	return ;
}
void dfz(int a)
{
	min1=int_inf;
	all=calsize(a,-1);
	if(all==1) return ;
	findcen(a,-1);
	vis[cen]=true;
	for(int i=head[cen];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			calval(u,cen,val[i]);
			while(t.size()){
				sum[t.front()]=true;
				t.pop();
			}
		}
	}
	while(q.size()){
		sum[q.front()]=false;
		q.pop();
	}
	for(int i=head[cen];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			dfz(u);
		}
	}
	return ;
}
int main()
{
	int i,j;
	int n,m;
	sum[0]=true;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n-1;i++){
		int a,b,v;
		scanf("%d%d%d",&a,&b,&v);
		add(a,b,v);
		add(b,a,v);
	}
	query.resize(m+1);
	ans.resize(m+1);
	for(int i=1;i<=m;i++){
		scanf("%d",&query[i]);
	}
	dfz(1);
	for(int i=1;i<=m;i++){
		if(ans[i]) printf("AYE\n");
		else printf("NAY\n");
	}
	return 0;
}