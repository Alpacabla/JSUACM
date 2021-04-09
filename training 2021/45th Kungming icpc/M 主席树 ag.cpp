/*
link: https://ac.nowcoder.com/acm/contest/12548/M
tags: 主席树维护静态区间比 k 小的数的和
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
int a[max_n],b[max_n];
int nn;
int tree[max_n],lson[(max_n<<6)],rson[(max_n<<6)];
int tot;
ll sum[(max_n<<6)];
int update(int last,int l,int r,int val)
{
	int now=++tot;
	sum[now]=sum[last]+b[val];
	if(l==r){
		return now;
	}
	int mid=(l+r)>>1;
	if(val<=mid) lson[now]=update(lson[last],l,mid,val),rson[now]=rson[last]; 
	else rson[now]=update(rson[last],mid+1,r,val),lson[now]=lson[last];
	return now;
}
void init(int n)
{
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	memcpy(b,a,sizeof(int)*(n+1));
	sort(b+1,b+1+n);
	nn=unique(b+1,b+1+n)-b-1;
	tree[0]=++now;
	for(int i=1;i<=n;i++){
		tree[i]=update(tree[i-1],1,nn,lower_bound(b+1,b+1+nn,a[i])-b);
	}
	return ;
}
ll query(int rr,int last,int l,int r,int val)
{
	if(l>val) return 0;
	if(r<=val){
		return sum[rr]-sum[last];
	}
	int mid=(l+r)>>1;
	return query(lson[rr],lson[last],l,mid,val)+query(rson[rr],rson[last],mid+1,r,val);
}
ll work(int l,int r)
{
	ll mex=0;
	ll res;
	while(1){
		res=mex;
		mex++;
		int k=upper_bound(b+1,b+1+nn,mex)-b-1;
		mex=query(tree[r],tree[l-1],1,nn,k);
		if(res==mex) break;
	}
	return mex+1;
}
void solve(int q,const int n)
{
	ll ans=0;
	for(int i=1;i<=q;i++){
		int l1,r1;
		scanf("%d%d",&l1,&r1);
		int l,r;
		l=(int)min((ans+l1)%n+1,(ans+r1)%n+1);
		r=(int)max((ans+l1)%n+1,(ans+r1)%n+1);
		ans=work(l,r);
		printf("%lld\n",ans);
	}
}
int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	init(n);
	solve(q,n);
	return 0;
}