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
const int max_n=2e3+5,max_m=3e3+5;
int head[max_n],to[max_m<<1],nxt[max_m<<1],val[max_m<<1],tot;
inline void add(int a,int b,int v){
	to[++tot]=b;
	nxt[tot]=head[a];
	val[tot]=v;
	head[a]=tot;
	return ;
}
bool inque[max_n];
int dis[max_n],cnt[max_n];
bool spfa(int s,int n)
{
	queue<int> q;
	for(int i=1;i<=n;i++) 
		dis[i]=int_inf,inque[i]=false,cnt[i]=0;
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++) head[i]=0;
		tot=1;
		for(int i=1;i<=m;i++){
			int a,b,v;
			cin>>a>>b>>v;
			add(a,b,v);
			if(v>=0) add(b,a,v);
		}
		if(spfa(1,n)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}