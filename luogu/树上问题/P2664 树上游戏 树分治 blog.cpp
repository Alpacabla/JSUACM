/*
link: https://www.luogu.com.cn/problem/P2664
tags: 淀粉质第三题，这题重要的是淀粉质的另一种形式做法，
	  因为要求从每个点出发的所有路径对这个点的贡献，所以分治成
	  对于每个点的最终答案来说
	  1. 从当前分治中心（重心）出发的所有路径的对分治中心的贡献
	  2. 从当前分治中心（重心）出发的所有路径对路径上的点的贡献
	  很容易想到这是互不重复且全部枚举了的分割

	  然后可以用各种数组来维护某个颜色（维护颜色，而不是点本身）的贡献
	  ，然后还可以删除某个子树的贡献，防止重复枚举，之后再加回来就行了，复杂度也不变。

	  还有就是忘记了是子树而不是链，要多一点想像力，不能把子树只看成链了。（错了这里调了三四个小时

	  最后就是有机会想一个树分治加 dp

*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
//#pragma GCC optimize(2)
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
int all;
int siz[max_n];
bool vis[max_n];
int getsize(int a,int fa)
{
	int w=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			w+=getsize(u,a);
		}
	}
	return siz[a]=w;
}
int min1;
int cen;
void getcen(int a,int fa)
{
	int max1=all-siz[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			getcen(u,a);
			max1=max(max1,siz[u]);
		}
	}
	if(max1<min1){
		min1=max1;
		cen=a;
	}
	return ;
}
ll ans[max_n];
int col[max_n];
bool firshow[max_n];
ll sum;
ll delans;
ll colsum[max_n];
queue<int> sonq,q;
void calfir(int a,int fa)
{
	bool flag=false;
	if(!firshow[col[a]]){
		q.push(a);
		flag=true;
		firshow[col[a]]=true;
		ans[cen]+=siz[a];
		colsum[col[a]]+=siz[a];
		sum+=siz[a];
	}
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			calfir(u,a);
		}
	}
	if(flag) firshow[col[a]]=false;
	return ;
}
void delfir(int a,int fa)
{
	bool flag=false;
	if(!firshow[col[a]]){
		flag=true;
		firshow[col[a]]=true;
		colsum[col[a]]-=siz[a];
		sum-=siz[a];
		delans+=siz[a];
	}
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			delfir(u,a);
		}
	}
	if(flag) firshow[col[a]]=false;
	return ;
}
ll tempsum;
void calans(int a,int fa,ll addans)
{
	bool flag=false;
	if(!firshow[col[a]]){
		flag=true;
		firshow[col[a]]=true;
		sonq.push(a);
		addans+=tempsum-colsum[col[a]];
	}
	ans[a]+=addans;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			calans(u,a,addans);
		}
	}
	if(flag) firshow[col[a]]=false;
	return ;
}
void solve(int a)
{
	calfir(a,-1);
	firshow[col[a]]=true;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			delans=0;
			delfir(u,a);
			tempsum=siz[cen]-siz[u];
			calans(u,a,sum-siz[u]);
			while(sonq.size()){
				int qq=sonq.front();
				sonq.pop();
				colsum[col[qq]]+=siz[qq];
				sum+=siz[qq];
			}
		}
	}
	sum=0;
	while(q.size()){
		int qq=q.front();
		q.pop();
		firshow[col[qq]]=false;
		colsum[col[qq]]=0;
	}
	return ;
}
void dfz(int a)
{
	all=getsize(a,-1);
	min1=int_inf;
	getcen(a,-1);
	
	sum=0;
	getsize(cen,-1);
	solve(cen);
	vis[cen]=true;
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
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",col+i);
	}
	for(int i=2;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfz(1);
	for(int i=1;i<=n;i++){
		printf("%lld\n",ans[i]);
	}
	return 0;
}