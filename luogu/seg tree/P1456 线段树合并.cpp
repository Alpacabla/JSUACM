/*
link: https://www.luogu.com.cn/problem/P1456
tags: 线段树合并的小板子，线段树合并的复杂度分析可以看 merge 的执行次数，
	  而 merge 的执行次数与合并次数以及这些被合并的树的节点数（如果树的节点又有动态插入，
	  那么就一定要注意了）有关，总的复杂度应该是基本等于空间复杂度。
	  删除的时候如果可以就把链都删掉这样稍微加快点速度。
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
const int lim=32768;
int tot,ls[max_n<<6],rs[max_n<<6],sz[max_n<<6],val[max_n<<6],root[max_n];
inline int newnode(){
	sz[++tot]=1;
	rs[tot]=ls[tot]=0;
	return tot;
}
int build(int l,int r,const int v)
{
	int now=newnode();
	if(l==r){
		val[now]=v;
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
int del(const int now,int l,int r,const int v)
{
	sz[now]--;
	if(sz[now]==0) {return 0;}
	if(l==r){
		return now;
	}
	int mid=(l+r)>>1;
	if(v<=mid) ls[now]=del(ls[now],l,mid,v);
	else rs[now]=del(rs[now],mid+1,r,v);
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
int get_max(const int now)
{
	if(!sz[rs[now]]){
		if(!sz[ls[now]]) return val[now];
		else return get_max(ls[now]);
	}else return get_max(rs[now]);
}
int fa[max_n];
inline int find(int a){
	return fa[a]?fa[a]=find(fa[a]):a;
}
int fight(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a==b) return -1;
	else{
		fa[b]=a;
		int maxa=get_max(root[a]),maxb=get_max(root[b]);
		root[a]=del(root[a],0,lim,maxa);
		root[b]=del(root[b],0,lim,maxb);
		root[a]=insert(root[a],0,lim,maxa/2);
		root[b]=insert(root[b],0,lim,maxb/2);
		merge(root[a],root[b]);
		return get_max(root[a]);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	int n;
	while(cin>>n){
		tot=0;
		for(i=1;i<=n;i++){
			int num;
			cin>>num;
			root[i]=build(0,lim,num);
			fa[i]=0;
		}
		int m;
		cin>>m;
		while(m--){
			int a,b;
			cin>>a>>b;
			cout<<fight(a,b)<<endl;
		}
	}
	return 0;
}