/*
link: https://loj.ac/p/6280
tags: 分块就是分块没什么好说的，只是这个写法很好，抄的别人的
	  维护块内前缀和以及块的前缀和达到 O(1) 查询，这样平均速度快一点，但是写起来复杂多了。
	  可以试下下次把块写成结构体。
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
ll sum1[max_n];
ll sum[300];
ll add[300];
int id[max_n];
int k;
void update(int l,int r,ll v)
{
	int sid=id[l],eid=id[r];
	if(sid==eid){
		int i;
		ll val=0;
		for(i=l;i<=r;i++){
			val+=v;
			sum1[i]+=val;
		}
		for(;id[i]==sid;i++){
			sum1[i]+=val;
		}
		for(i=sid;i<=k;i++){
			sum[i]+=val;
		}
	}else{
		ll val=0;
		for(int i=l;id[i]==sid;i++){
			val+=v;
			sum1[i]+=val;
			sum[sid]+=v;
		}
		for(int i=sid+1;i<eid;i++){
			val+=k*v;
			sum[i]+=val;
			add[i]+=v;
		}
		ll vv=0;
		for(int i=(eid-1)*k+1;i<=r;i++){
			vv+=v;
			val+=v;
			sum1[i]+=vv;
		}
		for(int i=r+1;id[i]==eid;i++){
			sum1[i]+=vv;
		}
		for(int i=eid;i<=k;i++){
			sum[i]+=val;
		}
	}
	return ;
}
int query(int l,int r,ll mod)
{
	ll res=0;
	int sid=id[l],eid=id[r];
	if(sid==eid){
		res=(sum1[r]-((l%k==1)?0:sum1[l-1])+(r-l+1)*add[sid])%mod;
	}else{
		res=(res+sum1[sid*k]-(l%k==1?0:sum1[l-1])+(sid*k-l+1)*add[sid])%mod;
		if(eid-1>=sid+1) res=(res+sum[eid-1]-sum[sid])%mod;
		res=(res+sum1[r]+(r-(eid-1)*k)*add[eid])%mod;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	k=max(2,(int)ceil(sqrt(n)));
	int now=1;
	for(int i=1;i<=n;i++){
		cin>>sum1[i];
		id[i]=now;
		sum[now]+=sum1[i];
		if(i%k==0) now++;
	}
	for(int i=n+1;i<=k*k;i++){
		id[i]=now;
		if(i%k==0) now++;
	}
	now--;
	for(int i=1;i<=now;i++){
		sum[i]+=sum[i-1];
		for(int j=(i-1)*k+2,end=i*k;j<=end;j++){
			sum1[j]+=sum1[j-1];
		}
	}
	for(int i=1;i<=n;i++){
		int opt,l,r;
		ll c;
		cin>>opt>>l>>r>>c;
		if(opt){
			cout<<query(l,r,c+1)<<endl;
		}else{
			update(l,r,c);
		}

	}
	return 0;
}