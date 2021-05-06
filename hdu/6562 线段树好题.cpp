/*
link: http://acm.hdu.edu.cn/showproblem.php?pid=6562
tags: 很好的题，难就难在对我来说很难讨论，push的细节太多了ORZ
	  要么最开始就讨论明白，要么就模拟清楚再做，而且要多考虑一般只要乘法加法就能
	  线段树维护
	  	// 1
		// 5 5
		// query 2 2
		// wrap 1 2 4
		// wrap 1 5 8
		// wrap 1 5 8
		// query 2 2
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
const ll mod=1e9+7;
struct seg{
	ll *sum,*sum10,*lazyx,*lazyadd,*lazyd;
	static const int n=1e5;

	int build(int ind,int l=1,int r=n)
	{
		lazyadd[ind]=sum[ind]=0;
		lazyx[ind]=1;
		lazyd[ind]=0;
		if(l==r){
			sum10[ind]=10;
			return sum10[ind];
		}
		int mid=(l+r)>>1;
		sum10[ind]+=build(to_l(ind),l,mid);
		sum10[ind]+=build(to_r(ind),mid+1,r);
		return sum10[ind];
	}
	void init(){
		sum=(ll *)malloc(sizeof(ll)*(max_n<<3));
		sum10=(ll *)malloc(sizeof(ll)*(max_n<<3));
		lazyx=(ll *)malloc(sizeof(ll)*(max_n<<3));
		lazyadd=(ll *)malloc(sizeof(ll)*(max_n<<3));
		lazyd=(ll *)malloc(sizeof(ll)*(max_n<<3));
		build(1);
		return ;
	}

	inline void push(int ind,int l,int mid,int r){
		if(lazyx[ind]!=1){
			int a=to_l(ind);
			sum[a]=(sum[a]*lazyx[ind])%mod;
			sum[a]=(sum[a]+(lazyadd[ind]*(mid-l+1)%mod))%mod;
			sum[a]=(sum[a]+(lazyd[ind]*sum10[a])%mod)%mod;
			sum10[a]=(sum10[a]*(lazyx[ind]*lazyx[ind]%mod))%mod;
			lazyd[a]=(lazyd[a]*lazyx[ind]+(lazyd[ind]*(lazyx[a]*lazyx[a]%mod)%mod))%mod;
			lazyx[a]=(lazyx[a]*lazyx[ind])%mod;
			lazyadd[a]=(lazyadd[a]*lazyx[ind])%mod;
			lazyadd[a]=(lazyadd[a]+lazyadd[ind])%mod;

			a=to_r(ind);
			sum[a]=(sum[a]*lazyx[ind])%mod;
			sum[a]=(sum[a]+(lazyadd[ind]*(r-mid)%mod))%mod;
			sum[a]=(sum[a]+(lazyd[ind]*sum10[a])%mod)%mod;
			sum10[a]=(sum10[a]*(lazyx[ind]*lazyx[ind]%mod))%mod;
			lazyd[a]=(lazyd[a]*lazyx[ind]+(lazyd[ind]*(lazyx[a]*lazyx[a]%mod)%mod))%mod;
			lazyx[a]=(lazyx[a]*lazyx[ind])%mod;
			lazyadd[a]=(lazyadd[a]*lazyx[ind])%mod;
			lazyadd[a]=(lazyadd[a]+lazyadd[ind])%mod;

			lazyx[ind]=1;
			lazyadd[ind]=0;
			lazyd[ind]=0;
		}
		return ;
	}

	inline void maintain(int ind,int l,int r){
		sum[ind]=(sum[to_l(ind)]+sum[to_r(ind)])%mod;
		sum10[ind]=(sum10[to_l(ind)]+sum10[to_r(ind)])%mod;
		return ;
	}

	void work(int ind,int l1,int r1,int val,int l=1,int r=n)
	{
		int mid=(l+r)>>1;
		push(ind,l,mid,r);
		if(l>r1||r<l1) return ;
		if(l>=l1&&r<=r1){
			sum[ind]=(sum[ind]*10)%mod;
			sum[ind]=(sum[ind]+val*1ll*(r-l+1)%mod)%mod;
			sum[ind]=(sum[ind]+val*sum10[ind])%mod;
			sum10[ind]=(sum10[ind]*100)%mod;

			lazyd[ind]=val;
			lazyx[ind]=10;
			lazyadd[ind]=val;
			return ;
		}
		work(to_l(ind),l1,r1,val,l,mid);
		work(to_r(ind),l1,r1,val,mid+1,r);
		maintain(ind,l,r);
		return ;
	}

	ll query(int ind,int l1,int r1,int l=1,int r=n)
	{
		int mid=(l+r)>>1;
		push(ind,l,mid,r);
		if(l>r1||r<l1) return 0;
		if(l>=l1&&r<=r1){
			return sum[ind];
		}
		ll a=query(to_l(ind),l1,r1,l,mid);
		a+=query(to_r(ind),l1,r1,mid+1,r);
		a%=mod;
		//maintain(ind,l,r);
		return a;
	}

	void clear()
	{
		free(sum);
		free(sum10);
		free(lazyx);
		free(lazyadd);
		free(lazyd);
	}
};
char s[10];
int main()
{
	int t;
	int cnt=0;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		printf("Case %d:\n",++cnt);
		seg t1;
		t1.init();
		for(int i=1;i<=m;i++){
			scanf("%s",s);
			if(s[0]=='w'){
				int l,r,val;
				scanf("%d%d%d",&l,&r,&val);
				t1.work(1,l,r,val);
			}else{
				int l,r;
				scanf("%d%d",&l,&r);
				printf("%lld\n",t1.query(1,l,r));
			}
		}
		t1.clear();
	}
	return 0;
}