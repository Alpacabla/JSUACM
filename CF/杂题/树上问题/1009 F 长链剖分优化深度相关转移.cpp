/*
link: https://codeforces.com/contest/1009/problem/F
tags: https://thomasguo666.github.io/post/solution-cf1009f/
	  长链剖分优化深度相关转移是，将长链上的统计然后把别的链上的合并过来
	  O（1）的转移方法是用对于每个点都做个指针，然后对于每个长链的头都申请
	  一片连续的链长大小的空间，然后它的链上儿子的指针位置就是在原空间往下移。
	  否则是一条新的链，新申请空间。
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
int son[max_n],dep[max_n],deep[max_n];
int len[max_n];
void dfs(int a,int fa)
{
	deep[a]=deep[fa]+1;
	dep[a]=deep[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			dfs(u,a);
			if(dep[u]>dep[son[a]]) son[a]=u;
		}
	}
	dep[a]=max(dep[a],dep[son[a]]);
	len[a]=len[son[a]]+1;
	return ;
}
int cnt[max_n];
int ind[max_n];
int ans[max_n];
int all;
void ldsu(int a,int fa)
{
	cnt[ind[a]]+=1;
	if(son[a]){
		ind[son[a]]=ind[a]+1;
		ldsu(son[a],a);
		ans[a]=ans[son[a]]+1;
		if(cnt[ind[a]+ans[a]]==1) ans[a]=0;
	}
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa&&u!=son[a]){
			ind[u]=all;
			all+=len[u];
			ldsu(u,a);
			for(int j=0;j<len[u];j++){
				cnt[ind[a]+j+1]+=cnt[ind[u]+j];
				if(cnt[ind[a]+j+1]>cnt[ind[a]+ans[a]]||(cnt[ind[a]+j+1]==cnt[ind[a]+ans[a]]&&j+1<ans[a])){
					ans[a]=j+1;
				}
			}
		}
	}

	return ;
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
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
	ind[1]=0;
	all=len[1];
	ldsu(1,0);
	for(int i=1;i<=n;i++){
		printf("%d\n",ans[i]);
	}
	return 0;
}