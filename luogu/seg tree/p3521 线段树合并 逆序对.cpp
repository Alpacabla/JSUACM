/*
link: https://www.luogu.com.cn/problem/P3521
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
const int max_n=2e5+5;
const int max_m=5e6+5;
struct node{
	int l,r,siz;
}nodes[max_m];
int tot;
int n;
namespace io{
	const int MAX_SIZE=1<<20;//一次性读取这么多字节
	char buf[MAX_SIZE],*p1=NULL,*p2=NULL;
	#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,MAX_SIZE,stdin),p1==p2))?EOF:*p1++)
	inline int read(){//其他类型也能读，自由发挥，注意读负数需要添加一个判断
		int x=0;char ch=gc();
		while (!isdigit(ch))ch=gc();
		while (isdigit(ch)){x=x*10+(ch^48);ch=gc();}
		return x;
	}
}
using namespace io;
int creat_link(int v,int l,int r)
{
	register int now=++tot;
	nodes[now].siz=1;
	if(l==r){
		return now;
	}
	register int mid=(l+r)>>1;
	if(v<=mid) nodes[now].l=creat_link(v,l,mid);
	else nodes[now].r=creat_link(v,mid+1,r);
	return now;
}
ll ans=0;
ll cnt;
void merge(int &l,int r)
{
	if(!l||!r){
		l=r?r:l;
		return ;
	}
	nodes[l].siz+=nodes[r].siz;
	cnt+=(ll)nodes[nodes[r].r].siz*nodes[nodes[l].l].siz;
	merge(nodes[l].l,nodes[r].l);
	merge(nodes[l].r,nodes[r].r);
	return ;
}
int init()
{
	int a;
	a=read();
	if(a==0){
		register int l,r;
		l=init();
		r=init();
		ll sum=(ll)nodes[l].siz*nodes[r].siz;
		cnt=0;
		merge(l,r);
		ans+=min(cnt,sum-cnt);
		return l;
	}else{
		return creat_link(a,1,n);
	}
}
int main()
{
	n=read();
	init();
	//dfs(1);
	printf("%lld\n",ans);
	return 0;
}