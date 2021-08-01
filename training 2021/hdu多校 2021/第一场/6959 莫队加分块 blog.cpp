/*
link: https://acm.hdu.edu.cn/showproblem.php?pid=6959
tags: 利用莫队需要 O(1) 修改的特性 所以使用 
	  分块 O(1)修改 O(sqrt n)询问 来组合，好！
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
const int max_n=1.1e5+5;
const int sqn=356;
int y[max_n];
struct node{
	int x1,y1,x2,y2;
	int ind;
	bool operator < (const node &a) const {
		return (x1/sqn==a.x1/sqn)?(x2<a.x2):(x1/sqn<a.x1/sqn);
	}
}q[max_n];
int ans[max_n];
int cnt[max_n];
int bcnt[max_n/sqn+5];
int bpos[max_n];
int query(int l,int r)
{
	int res=0;
	if(bpos[l]==bpos[r]){
		for(int i=l;i<=r;i++) res+=cnt[i]>=1;
		return res;
	}else{
		for(int i=l;bpos[i]==bpos[l];i++) res+=cnt[i]>=1;
		for(int i=bpos[l]+1;i<bpos[r];i++) res+=bcnt[i];
		for(int i=r;bpos[i]==bpos[r];i--) res+=cnt[i]>=1;
		return res;
	}
}
inline void del(int a){
	cnt[y[a]]--;
	if(cnt[y[a]]==0) bcnt[bpos[y[a]]]--;
	return ;
}
inline void add(int a){
	cnt[y[a]]++;
	if(cnt[y[a]]==1) bcnt[bpos[y[a]]]++;
	return ;
}
int update(int l1,int r1,int l2,int r2,int y1,int y2)
{
	while(l1>l2){
		add(--l1);
	}
	while(r1<r2){
		add(++r1);
	}
	while(l1<l2){
		del(l1++);
	}
	while(r1>r2){
		del(r1--);
	}
	return query(y1,y2);
}
inline void init()
{
	memset(cnt,0,sizeof(cnt));
	memset(bcnt,0,sizeof(bcnt));
}
int main()
{
	int t;
	for(int i=0;i<max_n;i++){
		bpos[i]=i/sqn;
	}
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<=n;i++){
			scanf("%d",y+i);
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d%d%d",&q[i].x1,&q[i].y1,&q[i].x2,&q[i].y2);
			q[i].ind=i;
		}
		sort(q+1,q+1+m);
		q[0].x1=q[1].x1;
		q[0].x2=q[1].x1-1;
		for(int i=1;i<=m;i++){
			ans[q[i].ind]=update(q[i-1].x1,q[i-1].x2,q[i].x1,q[i].x2,q[i].y1,q[i].y2);
		}
		for(int i=1;i<=m;i++){
			printf("%d\n",ans[i]);
		}
	}
	return 0;
}