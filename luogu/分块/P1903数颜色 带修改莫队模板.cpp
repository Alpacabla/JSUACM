/*
link: https://www.luogu.com.cn/problem/P1903
tags: 带修改的莫队的修改要记住不是直接修改而是回滚，
	  好好理解回滚这个词。
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
int sqn;
struct qq{
	int l,r;
	int ind;
	int ti;
	bool operator < (const qq &a) const {
		return l/sqn==a.l/sqn?(r/sqn==a.r/sqn?ti<a.ti:r/sqn<a.r/sqn):l/sqn<a.l/sqn;
	}

	qq(){}

	qq(int a,int b,int c,int d):l(a),r(b),ind(c),ti(d){}

}q[max_n];
int col[max_n];
int ch[max_n],chind[max_n];
int ans[max_n];
int cnt[max_n];
int sum=0;
inline void add(int ind){
	if(cnt[col[ind]]++==0) sum++;
}
inline void del(int ind){
	if(--cnt[col[ind]]==0) sum--;
}
inline void change(int ind,int &color,int l,int r)
{
	if(ind<=r&&ind>=l){
		del(ind);
		
		swap(col[ind],color);
		add(ind);
	}else{
		swap(col[ind],color);
	}
	return ;
}
void update(int l1,int r1,int l2,int r2,int ind,int last,int ti)
{
	while(l1<l2){
		del(l1++);
	}
	while(l1>l2){
		add(--l1);
	}
	while(r1<r2){
		add(++r1);
	}
	while(r1>r2){
		del(r1--);
	}
	while(ti>last){
		++last;
		change(chind[last],ch[last],l2,r2);
	}
	while(ti<last){
		change(chind[last],ch[last],l2,r2);
		last--;
	}
	ans[ind]=sum;
	return ;
}
void solve(int m)
{
	q[0]=qq(q[1].l,q[1].l-1,0,0);
	for(int i=1;i<=m;i++){
		update(q[i-1].l,q[i-1].r,q[i].l,q[i].r,q[i].ind,q[i-1].ti,q[i].ti);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	int qcnt=1,chcnt=0;

	sqn=ceil(pow(n,0.666));
	for(int i=1;i<=n;i++){
		cin>>col[i];
	}

	for(int i=1;i<=m;i++){
		char a;
		int l,r;
		cin>>a>>l>>r;
		if(a=='Q'){
			q[qcnt]=qq(l,r,qcnt,chcnt);
			qcnt++;
		}else{
			chind[++chcnt]=l;
			ch[chcnt]=r;
		}
	}

	sort(q+1,q+qcnt);

	solve(qcnt-1);

	for(int i=1;i<qcnt;i++){
		cout<<ans[i]<<endl;
	}

	return 0;
}