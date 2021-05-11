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
const int max_n=5e5+5;
const int lim=max_n-4;
ll a[max_n],d[max_n],tot=0;;
ll sum[max_n<<3];
inline void maintain(int ind){
	sum[ind]=__gcd(sum[to_l(ind)],sum[to_r(ind)]);
	return ;
}
void build(int ind=1,int l=1,int r=lim)
{
	if(l==r){
		sum[ind]=d[++tot];
		return ;
	}
	int mid=l+((r-l)>>1);
	build(to_l(ind),l,mid);
	build(to_r(ind),mid+1,r);
	maintain(ind);
	return ;
}
ll query(int l,int r,int ind=1,int l1=1,int r1=lim)
{
	if(l1>r||r1<l) return 0;
	if(l1>=l&&r1<=r){
		return sum[ind];
	}
	int mid=l1+((r1-l1)>>1);
	return __gcd(query(l,r,to_l(ind),l1,mid),query(l,r,to_r(ind),mid+1,r1));
}
void update(int i,ll v,int ind=1,int l1=1,int r1=lim)
{
	if(l1==r1){
		sum[ind]+=v;
		return ;
	}
	int mid=l1+((r1-l1)>>1);
	if(i<=mid) update(i,v,to_l(ind),l1,mid);
	else update(i,v,to_r(ind),mid+1,r1);
	maintain(ind);
	return ;
}
ll bit[max_n];
void add(int ind,ll v)
{
	while(ind<=lim){
		bit[ind]+=v;
		ind+=lowbit(ind);
	}
	return ;
}
ll get(int ind)
{
	ll res=0;
	while(ind){
		res+=bit[ind];
		ind-=lowbit(ind);
	}
	return res;
}
void init(int n)
{
	for(int i=1;i<=n;i++){
		bit[i]+=d[i];
		if(i+lowbit(i)<=n+1) bit[i+lowbit(i)]+=bit[i];
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	}
	build();
	init(n);
	for(int i=1;i<=m;i++){
		char ch;
		int l,r;
		cin>>ch>>l>>r;
		if(ch=='Q'){
			ll t=get(l);
			if(l+1<=r) t=__gcd(t,query(l+1,r));
			cout<<abs(t)<<endl;
		}else{
			ll k;
			cin>>k;
			update(l,k);
			update(r+1,-k);
			add(l,k);
			add(r+1,-k);
		}
	}
	return 0;
}