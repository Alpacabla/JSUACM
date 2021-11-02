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
int num[max_n];
int v[max_n];
int cnt;
int sum[max_n<<5],rs[max_n<<5],ls[max_n<<5],root[max_n<<5];
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
}
int build_tree(const int l,const int r)
{
	int now=cnt++;
	if(l==r){
		return now;
	}
	ls[now]=build_tree(l,(l+r)>>1);
	rs[now]=build_tree(((l+r)>>1)+1,r);
	return now;
}
void update(const int u,const int l,const int r,const int ind)
{
	int now=cnt++;
	sum[now]=sum[u]+1;
	if(l==r){
		return ;
	}
	if(ind<=((l+r)>>1)) update(ls[u],l,(l+r)>>1,ind),rs[now]=rs[u],ls[now]=now+1;
	else update(rs[u],((l+r)>>1)+1,r,ind),ls[now]=ls[u],rs[now]=now+1;
	return ;
}
int check(const int u,const int v,const int l,const int r,const int k)
{
	if(l==r){
		return l;
	}
	int x=sum[ls[u]]-sum[ls[v]];
	if(k<=x) return check(ls[u],ls[v],l,(l+r)>>1,k);
	else return check(rs[u],rs[v],((l+r)>>1)+1,r,k-x);
}
int init(const int n)
{
	int i;
	memcpy(v,num,sizeof(int)*n);
	sort(v,v+n);
	int now=0;
	v[n]=1e9+2;
	for(i=0;i<n;i++){
		while(v[i]==v[i+1]) i++;
		v[now++]=v[i];
	}
	cnt=0;
	root[0]=build_tree(0,now);
	for(i=1;i<=n;i++){
		root[i]=cnt;
		update(root[i-1],0,now,lower_bound(v,v+now,num[i-1])-v);
	}
	return now;
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int i,j;
	int n,m;
	n=io::read(),m=io::read();
	//scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		num[i]=io::read();
		//scanf("%d",num+i);
	}
	n=init(n);
	while(m--){
		int l,r,k;
		l=io::read(),r=io::read(),k=io::read();
		//scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",v[check(root[r],root[l-1],0,n,k)]);
	}
	return 0;
}