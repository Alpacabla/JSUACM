/*
link: https://www.luogu.com.cn/problem/P5490
tags: 扫描线模板做法1 维护区间最小值以及最小值的数量，以求被覆盖范围。
	  学弟问才发现原来我完全不会扫描线ORZ
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
};
int res[max_n<<2],min1[max_n<<2],cntmin1[max_n<<2],add[max_n<<2],len[max_n<<2];
int indl[max_n],indr[max_n];
int k;
void build(vector<int> &coo,int ind,int l,int r)
{
	if(l==r){
		if(l+1==k){
			len[ind]=0;
			return ;
		}
		cntmin1[ind]=len[ind]=coo[l+1]-coo[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(coo,to_l(ind),l,mid);
	build(coo,to_r(ind),mid+1,r);
	cntmin1[ind]=len[ind]=len[to_l(ind)]+len[to_r(ind)];
	return ;
}
inline void push_down(int ind)
{
	if(add[ind]){
		int a=to_l(ind);
		add[a]+=add[ind];
		min1[a]+=add[ind];
		if(min1[a]!=0){
			res[a]=len[a];
		}else res[a]=len[a]-cntmin1[a];

		a=to_r(ind);
		add[a]+=add[ind];
		min1[a]+=add[ind];
		if(min1[a]!=0){
			res[a]=len[a];
		}else res[a]=len[a]-cntmin1[a];

		add[ind]=0;
	}
	return ;
}
inline void maintain(int ind){
	if(min1[to_l(ind)]==min1[to_r(ind)]){
		min1[ind]=min1[to_l(ind)];
		cntmin1[ind]=cntmin1[to_l(ind)]+cntmin1[to_r(ind)];
	}else{
		if(min1[to_l(ind)]<min1[to_r(ind)]){
			min1[ind]=min1[to_l(ind)];
			cntmin1[ind]=cntmin1[to_l(ind)];
		}else{
			min1[ind]=min1[to_r(ind)];
			cntmin1[ind]=cntmin1[to_r(ind)];
		}
	}
	res[ind]=res[to_l(ind)]+res[to_r(ind)];
}
void update(int ind,int l,int r,int l1,int r1,int k)
{
	if(l1>r||r1<l) return ;
	if(l1>=l&&r1<=r){
		min1[ind]+=k;
		if(min1[ind]!=0){
			res[ind]=len[ind];
		}else res[ind]=len[ind]-cntmin1[ind];
		add[ind]+=k;
		return ;
	}
	push_down(ind);
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
		v[++tot].y=b.y2;
		v[tot].ind=i;
	}
	sort(coo.begin()+1,coo.end());
	k=unique(coo.begin()+1,coo.end())-coo.begin();
	sort(v.begin()+1,v.end(),[](const ts a,const ts b) -> bool{
		return a.y<b.y;
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
		ans+=1ll*res[1]*(v[i].y-last);
		if(vis[kk]){
			update(1,l,r,1,k,-1);
		}else{
			vis[kk]=true;
			update(1,l,r,1,k,1);
		}

		last=v[i].y;
	}
	cout<<ans<<endl;
	return 0;
}