/*
link: https://www.luogu.com.cn/problem/P2801
tags: 块内提前排序，这题主要是数据范围比较好，所以勉强能分块，调整块的时候因为是
	  有序数组归并所以可以用归并排序稍微提下速度，去掉调整时的 log
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
const int max_n=1.5e6+5;
struct node{
	int a;
	int ind;
	bool operator < (const node b) const {
		return a<b.a;
	}
}a[max_n];
int id[max_n];
int k;
int add[1205];
#define check(i,l,r) ((i<=r&&i>=l))
node t1[1005],t2[1005];
int tot1,tot2;
inline void change(int l,int r,int l1,int r1,int val)
{
	tot1=tot2=0;
	for(int i=l;i<=r;i++){
		if(check(a[i].ind,l1,r1)){
			t1[tot1]=a[i];
			t1[tot1++].a+=val;
		}else{
			t2[tot2++]=a[i];
		}
	}
	merge(t1,t1+tot1,t2,t2+tot2,a+l);
	return ;
}
void update(int l,int r,int val)
{
	int lid=id[l],rid=id[r];
	if(lid==rid){
		change((lid-1)*k+1,(lid)*k,l,r,val);
	}else{
		change((lid-1)*k+1,(lid)*k,l,r,val);
		for(int i=lid+1;i<rid;i++) add[i]+=val;
		change((rid-1)*k+1,(rid)*k,l,r,val);
	}
	return ;
}
int query(int l,int r,int val)
{
	int lid=id[l],rid=id[r];
	int res=0;
	if(lid==rid){
		val-=add[lid];
		for(int i=(lid-1)*k+1;id[i]==lid;i++){
			if(check(a[i].ind,l,r)&&val<=a[i].a){
				res++;
			}
		}
	}else{
		for(int i=(lid-1)*k+1;id[i]==lid;i++){
			if(check(a[i].ind,l,r)&&val-add[lid]<=a[i].a){
				res++;
			}
		}
		for(int i=lid+1;i<rid;i++){
			int x=lower_bound(a+(i-1)*k+1,a+(i*k)+1,(node){val-add[i],0})-a;
			res+=(i*k)-x+1;
		}
		for(int i=(rid-1)*k+1;id[i]==rid;i++){
			if(check(a[i].ind,l,r)&&val-add[rid]<=a[i].a){
				res++;
			}
		}
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
	k=max(2,(int)ceil(sqrt(n)));
	int now=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
		a[i].ind=i;
		id[i]=now;
		if(i%k==0){
			now++;
		}
	}
	for(int i=n+1;i<=k*k;i++){
		id[i]=now;
		a[i].ind=i;
		if(i%k==0) now++;
	}
	for(int i=1;i<=k;i++){
		sort(a+(i-1)*k+1,a+(i)*k+1);
	}
	for(int i=1;i<=q;i++){
		char ch;
		int l,r,v;
		cin>>ch>>l>>r>>v;
		if(ch=='A'){
			cout<<query(l,r,v)<<endl;
		}else{
			update(l,r,v);
		}
	}
	return 0;
}