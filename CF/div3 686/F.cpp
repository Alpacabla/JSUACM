/*
link: https://codeforces.com/contest/1454/problem/F
tags: 二分加二分 有双重二分那味了
	  做法来自：https://www.cnblogs.com/phyger/p/14043816.html
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
const int max_n=2e5+5;
int min1[max_n<<2],max1[max_n<<2];
int num[max_n],tot;
#define maintain(a) (min1[a]=min(min1[to_r(a)],min1[to_l(a)]),max1[a]=max(max1[to_l(a)],max1[to_r(a)]))
void build(int l,int r,int ind)
{
	if(l==r){
		cin>>num[tot];
		max1[ind]=min1[ind]=num[tot++];
		return ;
	}
	int mid=(l+r)>>1;
	build(l,mid,to_l(ind));
	build(mid+1,r,to_r(ind));
	maintain(ind);
	return ;
}
int querymin(int l,int r,int ll,int rr,int ind)
{
	if(l>rr||r<ll) return int_inf;
	if(l>=ll&&r<=rr){
		return min1[ind];
	}
	int mid=(l+r)>>1;
	return min(querymin(l,mid,ll,rr,to_l(ind)),querymin(mid+1,r,ll,rr,to_r(ind)));
}
int lastmax[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		tot=1;
		build(1,n,1);
		int max1=-1;
		bool flag=false;
		int x,y,z;
		lastmax[n+1]=-1;
		for(int i=n;i>=1;i--){
			lastmax[i]=max(num[i],lastmax[i+1]);
		}
		for(int i=1;i<=n;i++){
			max1=max(max1,num[i]);
			int l=i+1,r=n-1;
			int ans=-1;
			while(l<=r){
				int mid=(l+r)>>1;
				int qmin=querymin(1,n,i+1,mid,1);
				if(qmin<max1){
					r=mid-1;
				}else{
					if(qmin>max1){
						l=mid+1;
					}else{
						int lastmax1=lastmax[mid+1];
						if(lastmax1==max1){
							ans=mid;
							break;
						}else{
							if(lastmax1<max1){
								r=mid-1;
							}else{
								l=mid+1;
							}
						}
					}
				}
			}
			if(~ans){
				flag=true;
				x=i;
				y=ans-x;
				z=n-x-y;
				break;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
			cout<<x<<" "<<y<<" "<<z<<endl;
		}else cout<<"NO"<<endl;
	}
	return 0;
}