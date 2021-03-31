/*
link: https://www.luogu.com.cn/problem/P5579
tags: 二分线段树，我的线段树水平实在是太弱了，因为是单调的所以可以线段树上二分查找。芜湖
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
vector<ll> num;
ll sum[max_n<<2],min1[max_n<<2],tobe[max_n<<2];
ll pre[max_n];
ll last[max_n<<2];
bool flag[max_n<<2];
inline void maintain(int l,int r,int ind){
	sum[ind]=sum[to_l(ind)]+sum[to_r(ind)];
	min1[ind]=min1[to_r(ind)];
	return ;
}
ll now;
inline void push_down(int l,int r,int ind){
	if(flag[ind]){
		flag[ind]=false;
		sum[ind]=(r-l+1)*tobe[ind];
		if(l!=r){
			flag[to_l(ind)]=flag[to_r(ind)]=true;
			tobe[to_l(ind)]=tobe[to_r(ind)]=tobe[ind];
			last[to_l(ind)]=last[to_r(ind)]=last[ind];
		}
		min1[ind]=tobe[ind];
	}
	sum[ind]+=1ll*(now-last[ind])*(pre[r]-pre[l-1]);
	min1[ind]+=1ll*(now-last[ind])*(num[r]);
	last[ind]=now;
	return ;
}
void build(int l,int r,int ind)
{
	if(l>=r){
		last[ind]=min1[ind]=sum[ind]=0;
		return ;
	}
	build(l,(l+r)>>1,to_l(ind));
	build(((l+r)>>1)+1,r,to_r(ind));
	maintain(l,r,ind);
	return ;
}
ll ans;
void check(int l,int r,int ind,const ll v)
{
	if(l>r) return ;
	push_down(l,r,ind);
	if(min1[ind]>=v){ 
		ans+=sum[ind]-1ll*(r-l+1)*v;
		flag[ind]=true;
		tobe[ind]=v;
		last[ind]=now;
		push_down(l,r,ind);
		return ;
	}
	if(l==r) return ;
	check(l,(l+r)>>1,to_l(ind),v);
	if(min1[to_l(ind)]>=v&&l!=r) check(((l+r)>>1)+1,r,to_r(ind),v);
	else if(l!=r) push_down(((l+r)>>1)+1,r,to_r(ind));
	maintain(l,r,ind);
	return ;
}
int main()
{
	int i,j;
	int n,m;
	scanf("%d%d",&n,&m);
	num.resize(n+1);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		num[i]=a;
	}
	sort(num.begin()+1,num.end(),[](const int a,const int b) -> bool {
		return a>b;
	});
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+num[i];
	build(1,n,1);
	while(m--){
		ll a,b;
		scanf("%lld %lld",&a,&b);
		ans=0;
		now=a;
		check(1,n,1,b);
		printf("%lld\n",ans);
	}
	return 0;
}