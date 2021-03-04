/*
link: https://pintia.cn/problem-sets/994805046380707840/problems/994805047638999040
tags: 贪心 线段树维护最小值 区间查询和修改
	  
	  贪心在于对于r要小的区间，可以直接使用它能使用的最大流量（即最小值），并不会影响最后结果
	  即便后面的区间和它有重叠区域也并不影响最终和，因为减少前面区间的流量并不能使后面区间能
	  使用超过减少值的更多流量，并且先使用前面区间可以带来正确的最优选择。
	  还有就是一个很显然的对于相同r的区间可以只考虑最大的l，但是其实靠不考虑都一样。
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
struct node{
	int l,r;
	bool operator < (const node a) const {
		if(r==a.r) return l<a.l;
		return r<a.r;
	}
}nodes[max_n];
ll a[max_n];
ll min1[max_n<<2],lazy[max_n<<2];
int tot;
#define maintain(ind)  min1[ind]=min(min1[to_r(ind)],min1[to_l(ind)])
inline void push_down(int ind)
{
	if(lazy[ind]){
		min1[ind]-=lazy[ind];
		lazy[to_l(ind)]+=lazy[ind];
		lazy[to_r(ind)]+=lazy[ind];
		lazy[ind]=0;
	}
	return ;
}
void build(int l,int r,int ind)
{
	if(l==r){
		min1[ind]=a[++tot];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,to_l(ind));
	build(mid+1,r,to_r(ind));
	maintain(ind);
	return ;
}
ll query(int l,int r,int l1,int r1,int ind)
{
	push_down(ind);
	if(l>r1||r<l1) return ll_inf;
	if(r<=r1&&l>=l1){
		return min1[ind];
	}
	int mid=(l+r)>>1;
	ll res=min(query(l,mid,l1,r1,to_l(ind)),query(mid+1,r,l1,r1,to_r(ind)));
	maintain(ind);
	return res;
}
void update(int l,int r,int l1,int r1,int ind,ll val)
{
	push_down(ind);
	if(l>r1||r<l1) return ;
	if(r<=r1&&l>=l1){
		lazy[ind]+=val;
		push_down(ind);
		return ;
	}
	int mid=(l+r)>>1;
	update(l,mid,l1,r1,to_l(ind),val);
	update(mid+1,r,l1,r1,to_r(ind),val);
	maintain(ind);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,q;
	cin>>n>>q;
	tot=0;
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	build(1,n-1,1);
	for(int i=1;i<=q;i++){
		int l,r;
		cin>>l>>r;
		if(l>r){
			swap(l,r);
		}
		l+=1;
		nodes[i].l=l;
		nodes[i].r=r;
	}
	sort(nodes+1,nodes+1+q);
	int now=1;
	ll ans=0;
	for(now=1;now<=q;now++){
		//while(now<q&&(nodes[now+1].r==nodes[now].r||nodes[now].r<i)) now++;
		
		ll add=query(1,n-1,nodes[now].l,nodes[now].r,1);
		//cout<<add<<endl;
		//cout<<endl;
		ans+=add;
		update(1,n-1,nodes[now].l,nodes[now].r,1,add);
	}
	cout<<ans<<endl;
	return 0;
}