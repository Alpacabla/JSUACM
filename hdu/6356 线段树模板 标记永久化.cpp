/*
link: http://acm.hdu.edu.cn/showproblem.php?pid=6356
tags: 这题首先是多次区间修改，一次查询，而且操作刚好适用于 st 表，应该要更快
	  
	  这里使用线段树加标记永久化，虽然输入量很大，但是它保证了输入随机，所以
	  必须要运用标记进行合理的剪枝，防止 TLE ，但是这里有个容易犯错的地方就是
	  标记永久化的时候如果还使用了 maintain 一定要带上自己这个节点一起来求此
	  区间信息，因为永久化，所以当前节点的信息并不会被下放，所以当前节点并不等价于
	  下面的两个节点维护的信息之和。
*/
#include<bits/stdc++.h>
#pragma GCC optimize(2) 
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_m=5e6+5;
const int max_n=1e5+5;
unsigned int f[max_m*3];
inline unsigned int solve(unsigned int &x,unsigned int &y,unsigned int &z){
	x=x^(x<<11);
	x=x^(x>>4);
	x=x^(x<<5);
	x=x^(x>>14);
	unsigned int w=x^(y^z);
	x=y;
	y=z;
	z=w;
	return z;
}
inline void init(int n,int m,unsigned int x,unsigned int y,unsigned int z){
	for(int i=1;i<=m*3;i++){
		f[i]=solve(x,y,z);
	}
	return ;
}
int val[max_n<<2];
int min1[max_n<<2];
void build(int l,int r,int ind)
{
	min1[ind]=val[ind]=0;
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,to_l(ind));
	build(mid+1,r,to_r(ind));
	return ;
}
#define maintain(ind) min1[ind]=max(min1[ind],min(min1[(ind<<1)|1],min1[ind<<1]))
int cnt=0;
void update(int l,int r,int l1,int r1,int ind,int v)
{
	if(min1[ind]>=v) return ;
	if(l>=l1&&r<=r1){
		if(val[ind]<v) min1[ind]=val[ind]=v;
		return ;
	}
	int mid=(l+r)>>1;
	if(l1<=mid) update(l,mid,l1,r1,to_l(ind),v);
	if(r1>mid) update(mid+1,r,l1,r1,to_r(ind),v);
	maintain(ind);
	return ;
}
ll ans;
void dfs(int l,int r,int ind,int v)
{
	v=max(v,val[ind]);
	if(l==r){
		ans=ans^(1ll*l*v);
		return ;
	}
	int mid=(l+r)>>1;
	dfs(l,mid,to_l(ind),v);
	dfs(mid+1,r,to_r(ind),v);
	return ;
}
int main()
{
	int i,j;
	int t;
	const int mod=1<<30;
	scanf("%d",&t);
	while(t--){
		cnt=0;
		int n,m;
		unsigned int x,y,z;
		scanf("%d%d%u%u%u",&n,&m,&x,&y,&z);
		init(n,m,x,y,z);
		build(1,n,1);
		for(int i=1;i<=m;i++){
			update(1,n,min(f[3*i-2]%n+1,f[3*i-1]%n+1),max(f[3*i-2]%n+1,f[3*i-1]%n+1),1,f[3*i]%mod);
		}
		ans=0;
		dfs(1,n,1,0);
		printf("%lld\n",ans);
	}
	return 0;
}