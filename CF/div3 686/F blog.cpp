/*
link: https://codeforces.com/contest/1454/problem/F
tags: 枚举每个点的值作为中间区间的min值，然后贪心的找最近的满足题意的条件
	  做法来自：https://www.cnblogs.com/AEMShana/p/14040408.html
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
int querymax(int l,int r,int ll,int rr,int ind)
{
	if(l>rr||r<ll) return -1;
	if(l>=ll&&r<=rr){
		return max1[ind];
	}
	int mid=(l+r)>>1;
	return max(querymax(l,mid,ll,rr,to_l(ind)),querymax(mid+1,r,ll,rr,to_r(ind)));
}
map<int,int> premax,sufmax;
int sufpos[max_n],prepos[max_n];
//利用这两个维护对于每个i点，num[i]在前后缀出现的最后位置（后缀的最后位置是反过来的，不包括i
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
		sufmax.clear(),premax.clear();
		memset(prepos,0,sizeof(int)*(n+2));
		memset(sufpos,0,sizeof(int)*(n+2));
		for(int i=n;i>=1;i--){
			sufpos[i]=sufmax[num[i]];
			max1=max(max1,num[i]);
			sufmax[max1]=i;
		}
		max1=-1;
		for(int i=1;i<=n;i++){
			prepos[i]=premax[num[i]];
			max1=max(max1,num[i]);
			premax[max1]=i;
		}
		for(int i=2;i<=n-1;i++){
			int l=prepos[i],r=sufpos[i];
			if(l&&r){
				int qmin=querymin(1,n,l+1,r-1,1);
				if(qmin==num[i]){
					flag=true;
					x=l;
					y=r-1-l;
					z=n-x-y;
					break;
				}
			}
		}
		if(flag){
			cout<<"YES"<<endl;
			cout<<x<<" "<<y<<" "<<z<<endl;
		}else cout<<"NO"<<endl;
	}
	return 0;
}