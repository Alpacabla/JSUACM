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
struct node{
	int l,r;
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,h;
	cin>>n>>h;
	vector<node> a(n+1);
	vector<int> sum(n+1);
	vector<int> seg(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].r;
		seg[i]=seg[i-1]+a[i].r-a[i].l;
	}
	for(int i=2;i<=n;i++){
		sum[i-1]=sum[i-2]+a[i].l-a[i-1].r;
	}
	sum[n]=sum[n-1]+1e9+1;
	int ans=-1;
	for(int i=1;i<=n;i++){
		int k=lower_bound(sum.begin()+i,sum.end(),h+sum[i-1])-sum.begin();
		ans=max(ans,seg[k]-seg[i-1]+h);
	}
	cout<<ans<<endl;
	return 0;
}