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
const int max_n=3e4+5,max_m=5e3+(((int)3e4)<<1)+10;
int head[max_n],to[max_m],nxt[max_m],val[max_m],from[max_m],tot;
inline void add(int a,int b,int v){
	to[++tot]=b;
	nxt[tot]=head[a];
	val[tot]=v;
	from[tot]=a;
	head[a]=tot;
	return ;
}
bool inque[max_n];
int dis[max_n];
bool spfa(int s,int n)
{
	queue<int> q;
	for(int i=0;i<=n;i++) 
		dis[i]=-int_inf,inque[i]=false;
	dis[s]=0;
	q.push(s);
	inque[s]=true;
	while(!q.empty()){
		int a=q.front();
		inque[a]=false;
		q.pop();
		for(int i=head[a];i;i=nxt[i]){
			int &u=to[i];
			if(dis[u]<dis[a]+val[i]){
				dis[u]=dis[a]+val[i];
				if(!inque[u]){
					inque[u]=true;
					q.push(u);
				}
			}
		}
	}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,v;
		cin>>a>>b>>v;
		add(a-1,b,v);
	}
	for(int i=1;i<=n;i++){
		add(i,i-1,-1);
		add(i-1,i,0);
	}
	spfa(0,n);
	cout<<dis[n]<<endl;
	return 0;
}