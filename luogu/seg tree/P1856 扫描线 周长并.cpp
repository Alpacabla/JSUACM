/*
link: https://www.luogu.com.cn/problem/P5490
tags: 扫描线模板做法2 标记永久化 周长并
*/
#include<algorithm>
#include<iostream>
#include<vector>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
struct node{
	int x1,y1,x2,y2;
};
struct ts{
	int y;
	int ind;
	bool flag;
};
int val[max_n<<2],add[max_n<<2],len[max_n<<2];
int indl[max_n],indr[max_n];
int k;
void build(vector<int> &coo,int ind,int l,int r)
{
	if(l==r){
		if(l+1==k){
			len[ind]=0;
			return ;
		}
		len[ind]=coo[l+1]-coo[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(coo,to_l(ind),l,mid);
	build(coo,to_r(ind),mid+1,r);
	len[ind]=len[to_l(ind)]+len[to_r(ind)];
	return ;
}
inline void maintain(int ind){
	if(add[ind]==0) val[ind]=val[to_l(ind)]+val[to_r(ind)];
}
void update(int ind,int l,int r,int l1,int r1,int k)
{
	if(l1>r||r1<l) return ;
	if(l1>=l&&r1<=r){
		add[ind]+=k;
		if(add[ind]>0){
			val[ind]=len[ind];
		}
		if(add[ind]==0){
			if(l1==r1) val[ind]=0;
			else val[ind]=val[to_l(ind)]+val[to_r(ind)];
		}
		return ;
	}
	int mid=(l1+r1)>>1;
	update(to_l(ind),l,r,l1,mid,k);
	update(to_r(ind),l,r,mid+1,r1,k);
	maintain(ind);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<node> a(n+1);
	vector<ts> v(n*2+1);
	vector<int> coo(n*2+1);
	vector<bool> vis(n+1);
	int tot=0,tot1=0;
	for(int i=1;i<=n;i++){
		node &b=a[i];
		cin>>b.x1>>b.y1>>b.x2>>b.y2;
		coo[++tot1]=b.x1;
		coo[++tot1]=b.x2;
		v[++tot].y=b.y1;
		v[tot].ind=i;
		v[tot].flag=true;
		v[++tot].y=b.y2;
		v[tot].ind=i;
		v[tot].flag=false;
	}
	sort(coo.begin()+1,coo.end());
	k=unique(coo.begin()+1,coo.end())-coo.begin();
	sort(v.begin()+1,v.end(),[](const ts a,const ts b) -> bool{
		if(a.y==b.y) return a.flag>b.flag;
		else return a.y<b.y;
	});
	for(int i=1;i<v.size();i++){
		int &kk=v[i].ind;
		indl[i]=lower_bound(coo.begin()+1,coo.begin()+k,a[kk].x1)-coo.begin();
		indr[i]=lower_bound(coo.begin()+1,coo.begin()+k,a[kk].x2)-coo.begin()-1;
	}
	ll ans=0;
	int last=0;
	build(coo,1,1,k);
	
	for(int i=1;i<v.size();i++){
		int &kk=v[i].ind;
		int &l=indl[i];
		int &r=indr[i];
		if(vis[kk]){
			update(1,l,r,1,k,-1);
		}else{
			vis[kk]=true;
			update(1,l,r,1,k,1);
			ans+=val[1]-last;
		}
		last=val[1];
	}
	ans*=2;
	tot1=0,tot=0;
	for(int i=1;i<=n;i++){
		node &b=a[i];
		coo[++tot1]=b.y1;
		coo[++tot1]=b.y2;
		v[++tot].y=b.x1;
		v[tot].ind=i;
		v[tot].flag=true;
		v[++tot].y=b.x2;
		v[tot].ind=i;
		v[tot].flag=false;
	}
	sort(coo.begin()+1,coo.end());
	k=unique(coo.begin()+1,coo.end())-coo.begin();
	sort(v.begin()+1,v.end(),[](const ts a,const ts b) -> bool{
		if(a.y==b.y) return a.flag>b.flag;
		else return a.y<b.y;
	});
	for(int i=1;i<v.size();i++){
		int &kk=v[i].ind;
		indl[i]=lower_bound(coo.begin()+1,coo.begin()+k,a[kk].y1)-coo.begin();
		indr[i]=lower_bound(coo.begin()+1,coo.begin()+k,a[kk].y2)-coo.begin()-1;
	}
	build(coo,1,1,k);
	last=0;
	for(int i=0;i<vis.size();i++) vis[i]=false;
	for(int i=1;i<v.size();i++){
		int &kk=v[i].ind;
		int &l=indl[i];
		int &r=indr[i];
		if(vis[kk]){
			update(1,l,r,1,k,-1);
		}else{
			vis[kk]=true;
			update(1,l,r,1,k,1);
		}
		ans+=abs(val[1]-last);
		last=val[1];
	}
	cout<<ans<<endl;
	return 0;
}