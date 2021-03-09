/*
link: https://www.acwing.com/problem/content/246/
tags: nlogn 的求最大连续子段和
	  这个性质可以用线段树维护，每个区间维护左最大连续，右最大连续
	  区间和，以及区间的最大连续子段和，就可以合并了，然后最后 query 的时候
	  可以把求得的区间摆起来做个 dp ，思路类似于原来 O(n) 的 dp
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
int val[max_n<<2],vall[max_n<<2],valr[max_n<<2];
int sum[max_n<<2];
int to[max_n];
inline void maintain(int ind){
	int max1=int_inf,l=to_l(ind),r=to_r(ind);
	max1=max(val[l],val[r]);
	max1=max(max1,valr[l]+vall[r]);
	val[ind]=max1;
	vall[ind]=max(sum[l]+vall[r],vall[l]);
	valr[ind]=max(sum[r]+valr[l],valr[r]);
	sum[ind]=sum[l]+sum[r];
	return ;
}
int now=0;
inline void change(int ind,int a){
	sum[ind]=val[ind]=vall[ind]=valr[ind]=a;
	return ;
}
void build(int l,int r,int ind)
{
	if(l==r){
		ll a;
		cin>>a;
		change(ind,a);
		to[++now]=ind;
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,to_l(ind));
	build(mid+1,r,to_r(ind));
	maintain(ind);
	return ;
}
void update(int x,int y)
{
	int ind=to[x];
	change(ind,y);
	ind/=2;
	while(ind!=0){
		maintain(ind);
		ind/=2;
	}
	return ;
}
int ans;
vector<int> ansto;
void query(int l,int r,int l1,int r1,int ind)
{
	if(r<l1||l>r1) return ;
	if(l>=l1&&r<=r1){
		ansto.push_back(ind);
		ans=max(ans,val[ind]);
		return ;
	}
	int mid=(l+r)>>1;
	query(l,mid,l1,r1,to_l(ind));
	query(mid+1,r,l1,r1,to_r(ind));
	return ;
}
int solve()
{
	int res=ans;
	int now=0;
	for(int i=0;i<ansto.size()-1;i++){
		int &ind=ansto[i];
		now=max(valr[ind],now+sum[ind]);
		res=max(res,max(now,now+vall[ansto[i+1]]));
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,q;
	cin>>n>>q;
	build(1,n,1);
	while(q--){
		int a;
		cin>>a;
		if(a==1){
			int l,r;
			cin>>l>>r;
			if(l>r) swap(l,r);
			ans=-int_inf;
			ansto.clear();
			query(1,n,l,r,1);
			ansto.push_back(0);
			cout<<solve()<<endl;
		}else{
			int x,y;
			cin>>x>>y;
			update(x,y);
		}
	}
	return 0;
}