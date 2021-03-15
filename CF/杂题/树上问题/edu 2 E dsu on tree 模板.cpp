/*
link: https://codeforces.com/contest/600/problem/E
tags: 树上启发式合并模板
	  重要的是它的复杂度证明，然后学习一下别人巧妙的写法，可以节约很多代码噶噶噶。
	  复杂度证明方面也是类似于每次缩减一半这种证明，就可以证明每个点最多也只会遍历
	  logn 次了。
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
int col[max_n];
int siz[max_n];
int son[max_n];
int calsiz(int a,int fa)
{
	siz[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			int res=calsiz(u,a);
			if(res>siz[son[a]]){
				son[a]=u;
			}
			siz[a]+=res;
		}
	}
	return siz[a];
}
int cnt[max_n];
int bigson;
ll ans[max_n];
int max1=-1;
ll sum=0;
void add(int a,int fa,int val)
{
	cnt[col[a]]+=val;
	if(cnt[col[a]]>max1) max1=cnt[col[a]],sum=col[a];
	else if(cnt[col[a]]==max1) sum+=col[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa&&u!=bigson){
			add(u,a,val);
		}
	}
	return ;
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
	bigson=son[a];
	add(a,fa,1);
	bigson=0;	//归零记得
	ans[a]=sum;
	if(!opt){
		add(a,fa,-1);
		max1=0;	//清空
		sum=0;
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
		cin>>col[i];
	}
	for(int i=2;i<=n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	calsiz(1,-1);
	dfs(1,-1,1);
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}