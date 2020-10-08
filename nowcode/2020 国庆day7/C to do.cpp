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
int dp[max_n];
struct node{
	int ind;
	int v;
	bool operator < (const node & a) const {
		return v<a.v;
	}
};
set<node> need[max_n];
int q[max_n];
int d[max_n];
int t[max_n];
int sum[max_n];
int sum1[max_n];
int ans[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,qq;
	cin>>n>>qq;
	for(i=1;i<=n;i++){
		char ch;
		cin>>ch>>t[i]>>d[i];
		if(ch=='-') d[i]=-d[i];
	}
	for(i=1;i<=n;i++){
		sum[i]=sum[i]+d[i];
	}
	sum[n+1]=0;
	int l,r;
	for(i=0;i<qq;i++){
		cin>>q[i];
		int l=1,r=n,mid,ind=-1;
		while(l<r){
			mid=(l+r)>>1;
			if(q[i]+sum[mid]>=0){
				ind=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		if(ind==-1){
			ans[i]=-1;
		}else{
			if(ind==n){
				ans[i]=0;
			}else{
				need[ind].insert((node){i,abs(sum[ind+1])-q[i]});
			}
		}
	}
	vetor<>
	for(i=n;i>=1;i--){

	}
	return 0;
}
