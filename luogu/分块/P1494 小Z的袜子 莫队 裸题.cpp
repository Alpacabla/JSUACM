/*
link: 
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
const int max_n=5e4+5;
int sqn;
int col[max_n];
struct qq{
	int l,r;
	int ind;
	bool operator < (const qq a) const{
		return l/sqn==a.l/sqn?r<a.r:l/sqn<a.l/sqn;
	}
}q[max_n];
ll ans1[max_n],ans2[max_n];
ll cnt[max_n];
ll res;
void update(int l1,int r1,int l2,int r2,int ind)
{
	while(l1>l2){
		ll y=cnt[col[--l1]]++;
		res+=(y<<1)|1;;
	}
	while(r1<r2){
		ll y=cnt[col[++r1]]++;
		res+=(y<<1)|1;
	}
	while(l1<l2){
		ll y=--cnt[col[l1++]];
		res-=(y<<1)|1;
	}
	while(r1>r2){
		ll y=--cnt[col[r1--]];
		res-=(y<<1)|1;
	}

	ll len=(r2-l2+1);
	if(res==len){
		ans1[ind]=0;
		ans2[ind]=1;
		return ;
	}
	ans1[ind]=res-len;
	ans2[ind]=len*(len-1);
	ll g=__gcd(ans1[ind],ans2[ind]);
	ans1[ind]/=g;
	ans2[ind]/=g;
	return ;
}
void solve(int m)
{
	res=0;
	q[0].l=q[1].l;
	q[0].r=q[1].l-1;
	for(int i=1;i<=m;i++){
		update(q[i-1].l,q[i-1].r,q[i].l,q[i].r,q[i].ind);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	sqn=ceil(n/(ceil(sqrt(m))));
	for(int i=1;i<=n;i++){
		cin>>col[i];
	}
	for(int i=1;i<=m;i++){
		int l,r;
		cin>>l>>r;
		q[i].l=l;
		q[i].r=r;
		q[i].ind=i;
	}
	sort(q+1,q+1+m);
	solve(m);
	for(int i=1;i<=m;i++){
		cout<<ans1[i]<<'/'<<ans2[i]<<'\n';
	}
	cout<<endl;
	return 0;
}