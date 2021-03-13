/*
link: https://www.acwing.com/problem/content/254/
tags: 点分的模板题，相对于第一题不同的是要维护一个 树状数组/平衡树/动态开点线段树
	  树状数组任意出错的是它存在 边权 为 0 的点时要给树状数组加一个偏移量

	  然后之前的做法是错的，复杂度有问题，错在把之前加入树集合的边权每次都遍历了一遍。
	  错误写法放在最下面了
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
//#pragma GCC optimize(2)
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=4e4+5;
int k;
int head[max_n],to[max_n<<1],nxt[max_n<<1],val[max_n<<1];
int tot;
inline void add(int a,int b,int v){
	to[++tot]=b;
	val[tot]=v;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int all;
int siz[max_n];
bool vis[max_n];
int getsize(int a,int fa)
{
	int w=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			w+=getsize(u,a);
		}
	}
	return siz[a]=w;
}
int min1;
int cen;
void getcen(int a,int fa)
{
	int max1=all-siz[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			getcen(u,a);
			max1=max(max1,siz[u]);
		}
	}
	if(max1<min1){
		min1=max1;
		cen=a;
	}
	return ;
}
int num1[max_n];
int cnt1;
int num[max_n];
int cnt=0;
int sum=0;
void getdist(int a,int fa,int len)
{
	int res=0;
	if(len>k) return ;
	num[cnt++]=len;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			getdist(u,a,len+val[i]);
		}
	}
	return ;
}
const int max_m=5e6+5;
int bit[max_m];
void add1(int ind)
{
	ind+=1;
	while(ind<=k){
		bit[ind]+=1;
		ind+=lowbit(ind);
	}
	return ;
}
void del(int ind)
{
	ind+=1;
	while(ind<=k){
		bit[ind]=0;
		ind+=lowbit(ind);
	}
	return ;
}
int query(int ind)
{
	ind+=1;
	int res=0;
	while(ind){
		res+=bit[ind];
		ind-=lowbit(ind);
	}
	return res;
}
void cal()
{
	for(int i=0;i<cnt;i++){
		sum+=query(k-num[i])+1;
	}
	for(int i=0;i<cnt;i++){
		num1[cnt1++]=num[i];
		add1(num[i]);
	}
	return ;
}
void solve(int a)
{
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			cnt=0;
			getdist(u,a,val[i]);
			cal();
		}
	}
	for(int i=0;i<cnt1;i++){
		del(num1[i]);
	}
	return ;
}
int dfz(int a)
{
	int res=0;
	all=getsize(a,-1);
	if(all==1) return 0;
	min1=int_inf;
	getcen(a,-1);
	vis[cen]=true;
	sum=0;
	cnt1=0;
	solve(cen);
	res+=sum;
	for(int i=head[cen];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			res+=dfz(u);
		}
	}
	return res;
}
namespace io{
	const int MAX_SIZE=1<<20;//一次性读取这么多字节
	char buf[MAX_SIZE],*p1=NULL,*p2=NULL;
	#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,MAX_SIZE,stdin),p1==p2))?EOF:*p1++)
	inline int read(){//其他类型也能读，自由发挥，注意读负数需要添加一个判断
		int x=0;char ch=gc();
		while (!isdigit(ch))ch=gc();
		while (isdigit(ch)){x=x*10+(ch^48);ch=gc();}
		return x;
	}
}
int main()
{
	int i,j;
	int n;
	while(1){
		n=io::read();
		k=io::read();
		if(!n&&!k) break;
		memset(vis,0,sizeof(bool)*(n+3));
		tot=0;
		memset(head,0,sizeof(int)*(n+3));
		n--;
		while(n--){
			int a,b,v;
			a=io::read();
			b=io::read();
			v=io::read();
			//a++,b++;
			add(a,b,v);
			add(b,a,v);
		}
		k=io::read();
		printf("%d\n",dfz(1));
	}
	return 0;
}
/*
   	  记一次错误写法

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
//#pragma GCC optimize(2)
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=4e4+5;
int k;
int head[max_n],to[max_n<<1],nxt[max_n<<1],val[max_n<<1];
int tot;
inline void add(int a,int b,int v){
	to[++tot]=b;
	val[tot]=v;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int all;
int siz[max_n];
bool vis[max_n];
int getsize(int a,int fa)
{
	int w=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			w+=getsize(u,a);
		}
	}
	return siz[a]=w;
}
int min1;
int cen;
void getcen(int a,int fa)
{
	int max1=all-siz[a];
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			getcen(u,a);
			max1=max(max1,siz[u]);
		}
	}
	if(max1<min1){
		min1=max1;
		cen=a;
	}
	return ;
}
list<int> li;
int num[max_n];
int cnt=0;
int sum=0;
void getdist(int a,int fa,int len)
{
	int res=0;
	if(len>k) return ;
	num[cnt++]=len;
	//sum+=(sets.size()-(sets.upper_bound(k-len)-sets.begin()));
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&u!=fa){
			getdist(u,a,len+val[i]);
		}
	}
	return ;
}
void cal()
{
	sort(num,num+cnt);
	auto l=li.begin();
	int d=0;
	for(int r=cnt-1;r>=0;r--){
		while(d<li.size()&&(*l)+num[r]<=k){
			l++;
			d++;
		}
		sum+=(d);
	}
	auto p=li.begin();
	l=li.begin();
	for(int r=0;r<cnt;r++){
		while(l!=li.end()&&(*l)<=num[r]){
			p=l;
			l++;
		}
		li.insert(l,num[r]);
	}
	return ;
}
void solve(int a)
{
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			cnt=0;
			getdist(u,a,val[i]);
			cal();
		}
	}
	return ;
}
int dfz(int a)
{
	int res=0;
	all=getsize(a,-1);
	if(all==1) return 0;
	min1=int_inf;
	getcen(a,-1);
	vis[cen]=true;
	sum=0;
	li.insert(li.begin(),0);
	solve(cen);
	res+=sum;
	li.clear();
	for(int i=head[cen];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			res+=dfz(u);
		}
	}
	return res;
}
namespace io{
	const int MAX_SIZE=1<<20;//一次性读取这么多字节
	char buf[MAX_SIZE],*p1=NULL,*p2=NULL;
	#define gc() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,MAX_SIZE,stdin),p1==p2))?EOF:*p1++)
	inline int read(){//其他类型也能读，自由发挥，注意读负数需要添加一个判断
		int x=0;char ch=gc();
		while (!isdigit(ch))ch=gc();
		while (isdigit(ch)){x=x*10+(ch^48);ch=gc();}
		return x;
	}
}
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int i,j;
	int n;
	//scanf("%d",&n);
	
	while(1){
		n=io::read();
		k=io::read();
		if(!n&&!k) break;
		memset(vis,0,sizeof(bool)*(n+3));
		tot=0;
		memset(head,0,sizeof(int)*(n+3));
		n--;
		while(n--){
			int a,b,v;
			a=io::read();
			b=io::read();
			v=io::read();
			//scanf("%d%d%d",&a,&b,&v);
			//a++,b++;
			add(a,b,v);
			add(b,a,v);
		}
		//cout<<"y"<<endl;
		//scanf("%d",&k);
		printf("%d\n",dfz(1));
	}
	return 0;
}
*/