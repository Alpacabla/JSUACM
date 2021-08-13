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
int a[max_n];
bool ok[max_n<<2];
int down[max_n<<2];
int summax[max_n<<2];
int tval[max_n<<2];
int tot=1;
const int mod=998244353;
namespace io{
	const int MAX_SIZE=1<<20;
	char buf[MAX_SIZE],*p1=NULL,*p2=NULL;
	#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,MAX_SIZE,stdin),p1==p2))?EOF:*p1++)
	inline int read(){
		int x=0;char ch=gc();
		while (!isdigit(ch))ch=gc();
		while (isdigit(ch)){x=x*10+(ch^48);ch=gc();}
		return x;
	}
};
using namespace io;
void push_down(int ind)
{
	if(down[ind]!=1){
		down[to_l(ind)]=1ll*down[to_l(ind)]*down[ind]%mod;
		down[to_r(ind)]=1ll*down[to_r(ind)]*down[ind]%mod;
		summax[to_l(ind)]=1ll*summax[to_l(ind)]*down[ind]%mod;
		summax[to_r(ind)]=1ll*summax[to_r(ind)]*down[ind]%mod;
		down[ind]=1;
	}
}
void maintain(int ind)
{
	ok[ind]=ok[to_l(ind)]&&ok[to_r(ind)];
	tval[ind]=(tval[to_l(ind)]+tval[to_r(ind)])%mod;
	summax[ind]=(summax[to_l(ind)]+summax[to_r(ind)])%mod;
}
void build(int ind,int l,int r)
{
	down[ind]=1;
	ok[ind]=false;
	if(l==r){
		int &k=a[l];
		int last=0;
		tval[ind]=k;
		while(k){
			last=lowbit(k);
			k-=lowbit(k);
		}
		tval[ind]-=last;
		ok[ind]=(tval[ind]==0);
		summax[ind]=last;
		return ;
	}
	int mid=(l+r)>>1;
	build(to_l(ind),l,mid);
	build(to_r(ind),mid+1,r);
	maintain(ind);
	return ;
}
void change2(int ind,int l1,int r1,int l2,int r2)
{
	if(l1>r2||r1<l2) return ;
	if(l1>=l2&&r1<=r2&&ok[ind]){
		summax[ind]=0;
		down[ind]=0;
		return ;
	}
	if(l1==r1){
		tval[ind]-=lowbit(tval[ind]);
		if(tval[ind]==0) ok[ind]=true;
		return ;
	}
	push_down(ind);
	int mid=(l1+r1)>>1;
	change2(to_l(ind),l1,mid,l2,r2);
	change2(to_r(ind),mid+1,r1,l2,r2);
	maintain(ind);
	return ;
}
void change3(int ind,int l1,int r1,int l2,int r2)
{
	if(l1>r2||r1<l2) return ;
	if(l1>=l2&&r1<=r2){
		summax[ind]=(summax[ind]*2)%mod;
		down[ind]=(down[ind]*2)%mod;
		return ;
	}
	push_down(ind);
	int mid=(l1+r1)>>1;
	change3(to_l(ind),l1,mid,l2,r2);
	change3(to_r(ind),mid+1,r1,l2,r2);
	maintain(ind);
	return ;
}
int ans=0;
void query(int ind,int l1,int r1,int l2,int r2)
{
	if(l1>r2||r1<l2) return ;
	if(l1>=l2&&r1<=r2){
		ans=(ans+tval[ind])%mod;
		ans=(ans+summax[ind])%mod;
		return ;
	}
	push_down(ind);
	int mid=(l1+r1)>>1;
	query(to_l(ind),l1,mid,l2,r2);
	query(to_r(ind),mid+1,r1,l2,r2);
	maintain(ind);
	return ;
}
int main()
{
	int t;
	t=read();
	while(t--){
		int n;
		n=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		tot=1;
		build(1,1,n);
		int q;
		q=read();
		while(q--){
			int opt,l1,l2;
			opt=read(),l1=read(),l2=read();
			if(opt==1){
				ans=0;
				query(1,1,n,l1,l2);
				printf("%d\n",ans);
			}else{
				if(opt==2){
					change2(1,1,n,l1,l2);
				}else{
					change3(1,1,n,l1,l2);
				}
			}
		}
	}
	return 0;
}