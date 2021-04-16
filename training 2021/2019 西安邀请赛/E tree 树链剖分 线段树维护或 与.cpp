/*
link: https://nanti.jisuanke.com/t/39272
tags: 模板题，具体模板对应标题，卡主点是维护与的时候要把32位都跑完而不是只跑一部分
	  还有就是 ((k>>i)&1)==1 左边部分一定要打括号
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
const int lim=1e5;
int a[max_n];
int head[max_n],to[max_n<<1],nxt[max_n<<1];
inline void add(int a,int b)
{
	static int tot=0;
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int top[max_n];
int siz[max_n],fa[max_n],bigson[max_n],dep[max_n];
int dfn[max_n],fdfn[max_n];
void dfs(int a,int pa)
{
	dep[a]=dep[pa]+1;
	fa[a]=pa;
	siz[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa){
			dfs(u,a);
			siz[a]+=siz[u];
			if(siz[u]>siz[bigson[a]]){
				bigson[a]=u;
			}
		}
	}
	return ;
}
void caltop(int a,int pa,int toptop)
{
	static int tot=0;
	top[a]=toptop;
	dfn[a]=++tot;
	fdfn[tot]=a;
	if(bigson[a]){
		caltop(bigson[a],a,top[a]);
	}
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=bigson[a]&&u!=pa){
			caltop(u,a,u);
		}
	}
	return ;
}
bool val[max_n<<3][32];
bool flag[max_n<<3][32];
//bool ed[max_n<<3];
bool chval[max_n<<3][32];
inline void push_down(int l,int mid,int r,int ind)
{
	if(l==r) return ;
	//ed[ind]=true;
	int v1,v2;
	v1=(mid-l+1)%2;
	v2=(r-mid)%2;
	for(int k=0;k<32;k++){
		if(flag[ind][k]){
			flag[ind][k]=false;
			flag[to_r(ind)][k]=flag[to_l(ind)][k]=true;
			chval[to_r(ind)][k]=chval[to_l(ind)][k]=chval[ind][k];
			val[to_l(ind)][k]=chval[ind][k]?v1:0;
			val[to_r(ind)][k]=chval[ind][k]?v2:0;
		}
	}
	return ;
}
inline void maintain(int ind)
{
	for(int k=0;k<32;k++){
		val[ind][k]=(val[to_r(ind)][k]+val[to_l(ind)][k])%2;
	}
	return ;
}
void update1(int l1,int r1,int num,int ind=1,int l=1,int r=lim)
{
	int mid=(l+r)>>1;
	push_down(l,mid,r,ind);
	if(l1>r||r1<l) return ;
	if(l>=l1&&r<=r1){
		//ed[ind]=true;
		for(int i=0;num>>i;i++){
			if((num>>i)&1){
				val[ind][i]=(r-l+1)%2;
				flag[ind][i]=1;
				chval[ind][i]=1;
			}
		}
		push_down(l,mid,r,ind);
		return ;
	}
	update1(l1,r1,num,to_l(ind),l,mid);
	update1(l1,r1,num,to_r(ind),mid+1,r);
	maintain(ind);
	return ;
}
void solve1(int k,int t)
{
	while(k!=0){
		int r=top[k];
		update1(dfn[r],dfn[k],t);
		k=fa[r];
	}
	return ;
}
void update2(int l1,int r1,int num,int ind=1,int l=1,int r=lim)
{
	int mid=(l+r)>>1;
	push_down(l,mid,r,ind);
	if(l1>r||r1<l) return ;
	if(l>=l1&&r<=r1){
		for(int i=0;i<32;i++){
			if(((num>>i)&1)==0){
				val[ind][i]=0;
				flag[ind][i]=1;
				chval[ind][i]=0;
			}
		}
		push_down(l,mid,r,ind);
		return ;
	}
	update2(l1,r1,num,to_l(ind),l,mid);
	update2(l1,r1,num,to_r(ind),mid+1,r);
	maintain(ind);
	return ;
}
void solve2(int k,int t)
{
	while(k!=0){
		int r=top[k];
		update2(dfn[r],dfn[k],t);
		k=fa[r];
	}
	return ;
}
int query(int l1,int r1,int ind=1,int l=1,int r=lim)
{
	int mid=(l+r)>>1;
	push_down(l,mid,r,ind);
	if(l1>r||r1<l) return 0;
	if(l>=l1&&r<=r1){
		int res=0;
		for(int i=0;i<32;i++){
			res+=(val[ind][i])?(1<<i):0;
		}
		return res;
	}
	int a=query(l1,r1,to_l(ind),l,mid);
	int b=query(l1,r1,to_r(ind),mid+1,r);
	maintain(ind);
	return a^b;
}
int solve3(int k)
{
	int res=0;
	while(k!=0){
		int r=top[k];
		res^=query(dfn[r],dfn[k]);
		k=fa[r];
	}
	return res;
}
int n;
void build(int ind,int l=1,int r=lim)
{
	static int tot=0;
	if(l==r){
		if(r<=n){
			int &num=a[fdfn[l]];
			for(int i=0;num>>i;i++){
				val[ind][i]=(num>>i)&1;
			}
		}
		return ;
	}
	int mid=(l+r)>>1;
	build(to_l(ind),l,mid);
	build(to_r(ind),mid+1,r);
	maintain(ind);
	return ;
}
int main()
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	for(int i=2;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	caltop(1,0,1);
	build(1);
	while(m--){
		int opt,k,t;
		scanf("%d%d%d",&opt,&k,&t);
		switch(opt){
			case 1:
				solve1(k,t);
				break;
			case 2:
				solve2(k,t);
				break;
			case 3:
				int res=solve3(k);
				if(res^t) puts("YES");
				else puts("NO");
				break;
		}
	}
	return 0;
}