/*
link: https://ac.nowcoder.com/acm/contest/11258/J
tags: bitset优化 贪心的状态转移
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
const int max_n=2e3+5;
const int max_m=5e3+5;
int head[max_n],to[max_m],nxt[max_m],val[max_m],tot;
inline void add(int a,int b,int v){
	to[++tot]=b;
	val[tot]=v;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
struct node{
	int a,v;
	bool operator < (const node b) const {
		return v>b.v;
	}
};
int dis[max_n][max_n];
bool vis[max_n];
void dij(int s,int *dis)
{
	memset(vis,0,sizeof(vis));
	priority_queue<node> q;
	q.push((node){s,0});
	dis[s]=0;
	while(!q.empty()){
		node t=q.top();
		q.pop();
		if(vis[t.a]) continue;
		vis[t.a]=true;
		for(int i=head[t.a];i;i=nxt[i]){
			int &u=to[i];
			if(dis[u]>t.v+val[i]){
				dis[u]=t.v+val[i];
				q.push((node){u,dis[u]});
			}
		}
	}
	return ;
}
bitset<2005> f[2005],ff[2005],pot[2005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++){
		int a,b,v;
		cin>>a>>b>>v;
		add(a,b,v);
		//dis[a][b]=v 注意这种写法可能会导致dij a 无法访问 -> b
	}
	for(int i=1;i<=n;i++){
		dij(i,dis[i]);
		f[i].set(i),ff[i].set(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=head[i];j;j=nxt[j]){
			int &u=to[j];
			if(dis[i][u]==val[j]){
				f[i].set(u),ff[u].set(i);
			}
		}
	}
	for(int i=1;i<=n;i++){
		vector<int> ind(n+1);
		for(int j=1;j<=n;j++){
			ind[j]=j;
			pot[j].reset();
			pot[j].set(j);
		}
		sort(ind.begin()+1,ind.end(),[&i](const int a,const int b)->bool{
			return dis[i][a]<dis[i][b];
		});
		for(int j=1;j<=n;j++){
			int &z=ind[j];
			//pot[z][z]=true;
			for(int k=head[z];k;k=nxt[k]){
				if(dis[i][z]+val[k]==dis[i][to[k]]){
					pot[to[k]]|=pot[z];
				}
			}
			//if((f[i]&ff[z]&pot[z]).any()) f[i][z]=ff[z][i]=true;
			//注意这一段的写法是错误的，因为此时的z是排了序的，那么如果我按排序顺序
			//做错误floyd，得到的结果肯定是正确的
			//所以要重起一个循环遍历一遍
		}
		for(int j=1;j<=n;j++) 
			if((f[i]&ff[j]&pot[j]).any()) 
				f[i].set(j),ff[j].set(i);
	}
	int cnt=0;
	for(int i=1;i<=n;i++) cnt+=ff[i].count();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]==int_inf){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}