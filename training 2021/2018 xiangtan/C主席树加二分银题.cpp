/*
link: https://vjudge.net/contest/426000#problem/C
tags: 二分+主席树 不是很难的 
	  不是很难，但是主席树能力真的太差了，码了至少四五个小时。
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
vector<int> val;
int root[max_n];
int now;
int left1[max_n<<5],right1[max_n<<5];
int cnt[max_n<<5];
#define maintain(a) cnt[a]=cnt[left1[a]]+cnt[right1[a]]
int build(int l,int r)
{
	int ind=++now;
	if(l==r){
		cnt[l]=0;
		return ind;
	}
	int mid=(l+r)>>1;
	left1[ind]=build(l,mid);
	right1[ind]=build(mid+1,r);
	maintain(ind);
	return ind;
}
int update(int l,int r,int last,int goal)
{
	int ind=++now;
	if(l==r){
		cnt[ind]=cnt[last]+1;
		return ind;
	}
	int mid=(l+r)>>1;
	if(goal<=mid){
		int t=update(l,mid,left1[last],goal);
		left1[ind]=t;
		right1[ind]=right1[last];
	}else{
		int t=update(mid+1,r,right1[last],goal);
		right1[ind]=t;
		left1[ind]=left1[last];
	}
	maintain(ind);
	return ind;
}
int check(int l,int r,int l1,int r1,int rk)
{
	if(l==r){
		return l;
	}
	int mid=(l+r)>>1;
	int x=cnt[left1[r1]]-cnt[left1[l1]];
	if(rk<=x){
		return check(l,mid,left1[l1],left1[r1],rk);
	}else{
		return check(mid+1,r,right1[l1],right1[r1],rk-x);
	}
}
void init(vector<int> a,vector<int> &b)
{
	sort(a.begin()+1,a.end());
	val=a;
	val.resize(unique(val.begin()+1,val.end())-val.begin());
	now=0;
	root[0]=build(1,val.size()-1);
	for(int i=1;i<b.size();i++){
		root[i]=update(1,val.size()-1,root[i-1],lower_bound(val.begin()+1,val.end(),b[i])-val.begin());
	}
	return ;
}
int solve(int a,int b)
{
	int l=1,r=b-a+1;
	int ans=1;
	while(l<=r){
		int mid=(l+r)>>1;
		int res=val[check(1,val.size()-1,root[a-1],root[b],b-a+1-mid+1)];
		if(res>=mid){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,q;
	while(cin>>n>>q){
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		init(a,a);
		for(int i=1;i<=q;i++){
			int aa,bb;
			cin>>aa>>bb;
			cout<<solve(aa,bb)<<endl;
		}
	}
	
	return 0;
}