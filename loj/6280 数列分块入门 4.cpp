/*
link: https://loj.ac/p/6280
tags: 分块就是分块没什么好说的，只是这个写法很好，抄的别人的
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
ll num[max_n];
ll sum[300];
ll add[300];
int id[max_n];
int k;
void update(int l,int r,ll v)
{
	int sid=id[l],eid=id[r];
	if(sid==eid){
		for(int i=l;i<=r;i++){
			num[i]+=v,sum[sid]+=v;
		}
	}else{
		for(int i=l;id[i]==sid;i++) num[i]+=v,sum[sid]+=v;
		for(int i=sid+1;i<eid;i++) add[i]+=v,sum[i]+=v*k;
		for(int i=r;id[i]==eid;i--) num[i]+=v,sum[eid]+=v;
	}
	return ;
}
int query(int l,int r,ll mod)
{
	ll res=0;
	int sid=id[l],eid=id[r];
	if(sid==eid){
		for(int i=l;i<=r;i++){
			res=(res+num[i]+add[sid])%mod;
		}
	}else{
		for(int i=l;id[i]==sid;i++) res=(res+num[i]+add[sid])%mod;
		for(int i=sid+1;i<eid;i++) res=(res+sum[i])%mod;
		for(int i=r;id[i]==eid;i--) res=(res+num[i]+add[eid])%mod;
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
	k=sqrt(n);
	int now=1;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		id[i]=now;
		sum[now]+=num[i];
		if(i%k==0) now++;
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