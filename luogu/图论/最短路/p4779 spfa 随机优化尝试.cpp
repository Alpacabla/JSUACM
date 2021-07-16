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
using namespace io;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5,max_m=2e5+5;
int head[max_n],to[max_m],nxt[max_m],val[max_m],tot;
inline void add(int a,int b,int v){
	to[++tot]=b;
	nxt[tot]=head[a];
	val[tot]=v;
	head[a]=tot;
	return ;
}
bool inque[max_n];
ll dis[max_n];
int cnt[max_n];
bool spfa(int s,int n)
{
	queue<int> q;
	for(int i=1;i<=n;i++) 
		dis[i]=ll_inf,inque[i]=false,cnt[i]=0;
	dis[s]=0;
	q.push(s);
	inque[s]=true;
	while(!q.empty()){
		int a=q.front();
		inque[a]=false;
		q.pop();
		for(int i=head[a];i;i=nxt[i]){
			int &u=to[i];
			if(dis[u]>dis[a]+val[i]){
				dis[u]=dis[a]+val[i];
				if(!inque[u]){
					inque[u]=true;
					q.push(u);
					cnt[u]++;
					if(cnt[u]==n) return true;
				}
			}
		}
	}
	return false;
}
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int n,m,s;
	n=read(),m=read(),s=read();
	vector<int> ind(m+1),a(m+1),b(m+1),v(m+1);
	for(int i=1;i<=m;i++){
		ind[i]=i;
		a[i]=read(),b[i]=read(),v[i]=read();
	}
	mt19937 rng(time(0));
	shuffle(ind.begin()+1,ind.end(),rng);
	for(int j=1;j<=m;j++){
		int &i=ind[j];
		add(a[i],b[i],v[i]);
	}
	spfa(s,n);
	for(int i=1;i<=n;i++) printf("%lld%c",dis[i],i==n?'\n':' ');
	return 0;
}