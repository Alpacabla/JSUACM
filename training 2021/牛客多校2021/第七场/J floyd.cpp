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
const int max_n=2e3+5;
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
int dis[max_n][max_n],dis1[max_n][max_n];
bool vis[max_n];
void dij(int s,int *dis)
{
	mesmet(vis,0,sizeof(vis));
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	memset(dis,0x3f,sizeof(dis));
	memset(dis1,0x3f,sizeof(dis1));
	for(int i=1;i<=m;i++){
		int a,b,v;
		cin>>a>>b>>v;
		dis1[a][b]=dis[a][b]=v;
	}
	for(int i=1;i<=n;i++){
		dij(i,dis[i]);
	}
	// for(int i=1;i<=n;i++) dis[i][i]=dis1[i][i]=0;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++){
	// 		for(int k=1;k<=n;k++){
	// 			dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	// 		}
	// 	}
	// }
	for(int i=1;i<=n;i++){
		for(int j)
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				// dis1[j][k]=min(dis1[j][k],dis1[j][i]+dis1[i][k]);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]!=dis1[i][j]){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}