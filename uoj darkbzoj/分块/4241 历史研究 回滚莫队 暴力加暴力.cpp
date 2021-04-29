/*
link: https://darkbzoj.tk/problem/4241
tags: 回滚莫队，只增莫队
      具体做法就是在换块的时候把指针归到改归的位置，然后每次的块内移动之后要删掉原来的贡献
      这样才能重算。适用于删除时无法统计答案，但增加时方便统计，比如最大值。
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
const int max_n=1.3e5;
int sqn;
struct qq{
	int l,r;
	int ind;
	bool operator < (const qq &a) const{
		return l/sqn==a.l/sqn?r<a.r:l/sqn<a.l/sqn;
	}
}q[max_n];
int val[max_n];
int v[max_n];
int cnt[max_n];
ll ans[max_n];
inline void bf(qq q){
	ll &a=ans[q.ind];
	for(int i=q.l;i<=q.r;i++){
		a=max(a,1ll*++cnt[v[i]]*val[v[i]]);
	}
	for(int i=q.l;i<=q.r;i++){
		--cnt[v[i]];
	}
	return ;
}
ll res;
inline void add(int i){
	res=max(res,1ll*++cnt[v[i]]*val[v[i]]);
	return ;
}
void update(int &l1,int &r1,int l2,int r2,int ind,int lst)
{
	while(r2>r1){
		add(++r1);
	}
	ll t=res;
	while(l1>l2){
		add(--l1);
	}
	ans[ind]=res;
	while(l1<lst){
		cnt[v[l1++]]--;
	}
	res=t;
	return ;
}
void solve(int m)
{
	int bl=-1;
	int l,r;
	for(int i=1;i<=m;i++){
		if(q[i].l/sqn==q[i].r/sqn) continue;
		if(i==1||q[i].l/sqn!=bl){
			bl=q[i].l/sqn;
			l=(bl+1)*sqn;
			r=(bl+1)*sqn-1;
			res=0;
			//重点记得清空统计数组，清空所有统计信息。
			memset(cnt,0,sizeof(cnt));
		}
		update(l,r,q[i].l,q[i].r,q[i].ind,(bl+1)*sqn);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	sqn=ceil(n/ceil(sqrt(m)));
	//sqn=333;
	for(int i=1;i<=n;i++){
		cin>>val[i];
		v[i]=val[i];
	}
	sort(val+1,val+1+n);
	int k=unique(val+1,val+1+n)-val;
	for(int i=1;i<=n;i++){
		v[i]=lower_bound(val+1,val+k,v[i])-val;
	}
	for(int i=1;i<=m;i++){
		cin>>q[i].l>>q[i].r;
		q[i].ind=i;
		if(q[i].l/sqn==q[i].r/sqn){
			bf(q[i]);
		}
	}
	sort(q+1,q+1+m);
	
	solve(m);

	for(int i=1;i<=m;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}