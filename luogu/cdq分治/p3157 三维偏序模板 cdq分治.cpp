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
struct BIT{
	vector<int> v;
	int n;

	void add1(int a,int val){
		if(a==0) return ;
		while(a){
			v[a]+=val;
			a-=lowbit(a);
		}
		return ;
	}

	int query1(int a){
		int res=0;
		if(a<=0) return res;
		while(a<=n){
			res+=v[a];
			a+=lowbit(a);
		}
		return res;
	}

	void add2(int a,int val){
		if(a==0) return ;
		while(a<=n){
			v[a]+=val;
			a+=lowbit(a);
		}
		return ;
	}

	int query2(int a){
		int res=0;
		if(a<=0) return res;
		while(a){
			res+=v[a];
			a-=lowbit(a);
		}
		return res;
	}

	void init(int siz){
		n=siz;
		v.clear();
		v.resize(siz+1);
		return ;
	}

};
struct node{
	int a,b;
	int ind;
}val[max_n],t[max_n];
int ind[max_n];
int res[max_n];
#define check(a,l,r) ((a>=l)&&(a<=r))
void sortside(int l,int mid,int r)
{
	// memcpy(val+l,t+l,(r-l+1)*sizeof(node));
	// sort(val+l,val+mid+1,[](const node a,const node b) -> bool{
	// 	return a.a<b.a;
	// });
	// sort(val+mid+1,val+r+1,[](const node a,const node b) -> bool{
	// 	return a.a<b.a;
	// });
	memcpy(t+l,val+l,(r-l+1)*sizeof(node));
	int now1=l,now2=mid+1;
	for(int i=l;i<=r;i++){
		if(check(t[i].ind,l,mid)){
			val[now1++]=t[i];
		}else{
			val[now2++]=t[i];
		}
	}
	return ;
}
BIT bit;
int n;
void work(int l,int mid,int r)
{
	int i,j;
	for(i=l,j=mid+1;i<=mid;i++){
		while(j<=r&&val[i].a>val[j].a){
			bit.add1(val[j].b-1,1);
			j++;
		}
		int bigger=bit.query1(val[i].b);
		res[val[i].b]+=bigger;
	}
	j--;
	while(j>=mid+1){
		bit.add1(val[j].b-1,-1);
		j--;
	}
	for(i=mid,j=r;j>=mid+1;j--){
		while(i>=l&&val[i].a>val[j].a){
			bit.add1(val[i].b-1,1);
			i--;
		}
		int bigger=bit.query1(val[j].b);
		res[val[j].b]+=bigger;
	}
	i++;
	while(i<=mid){
		bit.add1(val[i].b-1,-1);
		i++;
	}
	return ;
}
void cdq(int l,int r)
{
	if(l>=r) return ;
	int mid=(l+r)>>1;
	sortside(l,mid,r);
	work(l,mid,r);
	cdq(l,mid);
	cdq(mid+1,r);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int m;
	cin>>n>>m;
	bit.init(n);
	ll ans=0;
	for(int i=1;i<=n;i++){
		cin>>val[i].a;
		ans+=bit.query1(val[i].a);
		bit.add1(val[i].a-1,1);
		val[i].ind=i;
		ind[val[i].a]=i;
		val[i].b=n+1;
	}
	for(int i=1;i<=n;i++){
		bit.add1(val[i].a-1,-1);
	}
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		val[ind[k]].b=i;
	}
	for(int i=1;i<=n;i++){
		t[i]=val[i];
	}
	sort(val+1,val+n+1,[](const node a,const node b) -> bool{
	 	return a.a<b.a;
	});
	cdq(1,n);
	cout<<ans<<endl;
	for(int i=1;i<m;i++){
		ans-=res[i];
		cout<<ans<<endl;
	}
	return 0;
}