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
const int max_n=1e5+5;
ll mod;
ll sum[max_n<<2],add[max_n<<2],times[max_n<<2];
#define maintain(ind) ((sum[ind]=(sum[to_l(ind)]+sum[to_r(ind)])%mod))
void build(int l,int r,int ind)
{
	times[ind]=1;
	if(l==r){
		cin>>sum[ind];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,to_l(ind));
	build(mid+1,r,to_r(ind));
	maintain(ind);
	return ;
}
inline void push_down(int l,int r,int ind)
{
	sum[ind]=((sum[ind]*times[ind])%mod+(add[ind]*(r-l+1))%mod)%mod;
	if(l!=r){
		times[to_l(ind)]=(times[to_l(ind)]*times[ind])%mod;
		add[to_l(ind)]=(add[to_l(ind)]*times[ind])%mod;
		add[to_l(ind)]=(add[to_l(ind)]+add[ind])%mod;

		times[to_r(ind)]=(times[to_r(ind)]*times[ind])%mod;
		add[to_r(ind)]=(add[to_r(ind)]*times[ind])%mod;
		add[to_r(ind)]=(add[to_r(ind)]+add[ind])%mod;
	}
	times[ind]=1,add[ind]=0;
	return ;
}
void update1(int l,int r,int ind,int l1,int rr,ll v)
{
	push_down(l,r,ind);
	if(r<l1||l>rr) return ;
	if(r<=rr&&l>=l1){
		times[ind]=(times[ind]*v)%mod;
		add[ind]=(add[ind]*v)%mod;
		push_down(l,r,ind);
		return ;
	}
	int mid=(l+r)>>1;
	update1(l,mid,to_l(ind),l1,rr,v);
	update1(mid+1,r,to_r(ind),l1,rr,v);
	maintain(ind);
	return ;
}
void update2(int l,int r,int ind,int l1,int rr,ll v)
{
	push_down(l,r,ind);
	if(r<l1||l>rr) return ;
	if(r<=rr&&l>=l1){
		add[ind]=(add[ind]+v)%mod;
		push_down(l,r,ind);
		return ;
	}
	int mid=(l+r)>>1;
	update2(l,mid,to_l(ind),l1,rr,v);
	update2(mid+1,r,to_r(ind),l1,rr,v);
	maintain(ind);
	return ;
}
ll check(int l,int r,int ind,int l1,int rr)
{
	push_down(l,r,ind);
	if(r<l1||l>rr) return 0;
	if(r<=rr&&l>=l1){
		return sum[ind];
	}
	int mid=(l+r)>>1,res=0;
	res=(check(l,mid,to_l(ind),l1,rr)+check(mid+1,r,to_r(ind),l1,rr))%mod;
	maintain(ind);
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m>>mod;
	build(1,n,1);
	while(m--){
		int a,b,c,d;
		cin>>a;
		switch(a){
			case 1:
				cin>>b>>c>>d;
				update1(1,n,1,b,c,d);
				break;
			case 2:
				cin>>b>>c>>d;
				update2(1,n,1,b,c,d);
				break;
			case 3:
				cin>>b>>c;
				cout<<check(1,n,1,b,c)<<endl;
				break;
		}
	}
	return 0;
}