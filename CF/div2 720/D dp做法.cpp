// Problem: D. Nastia Plays with a Tree
// Contest: Codeforces - Codeforces Round #720 (Div. 2)
// URL: https://codeforces.com/contest/1521/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int head[max_n],to[max_n<<1],nxt[max_n<<1];
int du[max_n];
bool vise[max_n<<1];
int tot;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int dp[max_n][2],minv[max_n][3],minx[max_n][2];
vector<int> ans[4];
bool vis[max_n];
inline void init(int n)
{
	dp[0][1]=int_inf;
	memset(vise,0,sizeof(bool)*(2*n+4));
	memset(vis,0,sizeof(bool)*(n+4));
	memset(head,0,sizeof(int)*(n+4));
	memset(du,0,sizeof(int)*(n+4));
	tot=1;
	for(int i=0;i<4;i++) ans[i].clear();
	return ;
}
inline void _del(int a,int b){
	ans[0].push_back(a);
	ans[1].push_back(b);
	return ;
}
inline void _add(int a,int b){
	ans[2].push_back(a);
	ans[3].push_back(b);
	return ;
}
#define D(a) (dp[a][1]-dp[a][0])
void dfs(int a,int fa)
{
	int cnt=0;
	int v1,v2,v3;
	v1=v2=v3=0;
	
	int k1=0,k2=0;
	
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			dfs(u,a);
			cnt++;
			v1+=dp[u][0]+1;
			if(D(u)<=D(k1)){
				if(D(u)<D(k1)){
					k2=k1;
					k1=u;
				}else{
					k2=u;
				}
			}
		}
	}
	if(k1==0){
		dp[a][0]=dp[a][1]=0;
		return ;
	}
	v2=v1-1+D(k1);
	v3=v1-2+D(k1)+D(k2);
	dp[a][0]=min(v1,min(v2,v3));
	dp[a][1]=min(v1,v2);
	minv[a][0]=v1,minv[a][1]=v2,minv[a][2]=v3;
	minx[a][0]=k1,minx[a][1]=k2;
	return ;
}
void dfs1(int a,int fa,bool flag)
{
	int &v1=minv[a][0],&v2=minv[a][1],&v3=minv[a][2];
	int &k1=minx[a][0],&k2=minx[a][1];
	if(flag==0){
		if(dp[a][0]==0) return ;
		if(dp[a][0]==v1){
			for(int i=head[a];i;i=nxt[i]){
				int &u=to[i];
				if(u!=fa) {_del(a,u);vise[i]=vise[i^1]=true;dfs1(u,a,0);}
			}
		}else{
			if(dp[a][0]==v2){
				for(int i=head[a];i;i=nxt[i]){
					int &u=to[i];
					if(u!=fa&&u!=k1) {_del(a,u);vise[i]=vise[i^1]=true;dfs1(u,a,0);}
					else if(u==k1) {dfs1(u,a,1);}
				}
			}else{
				for(int i=head[a];i;i=nxt[i]){
					int &u=to[i];
					if(u!=fa&&u!=k1&&u!=k2) {_del(a,u);vise[i]=vise[i^1]=true;dfs1(u,a,0);}
					else if(u==k1||u==k2) {dfs1(u,a,1);}
				}
			}
		}
	}else{
		if(dp[a][1]==0) return ;
		if(dp[a][1]==v2){
			for(int i=head[a];i;i=nxt[i]){
				int &u=to[i];
				if(u!=fa&&u!=k1) {_del(a,u);vise[i]=vise[i^1]=true;dfs1(u,a,0);}
				else if(u==k1) {dfs1(u,a,1);}
			}
		}else{
			for(int i=head[a];i;i=nxt[i]){
				int &u=to[i];
				if(u!=fa) {_del(a,u);vise[i]=vise[i^1]=true;dfs1(u,a,0);}
			}
		}
	}
	return ;
}
int k1,k2;
void dfs2(int a,int fa)
{
	int flag=0;
	vis[a]=true;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vise[i]&&fa!=u){
			dfs2(u,a);
			flag++;
		}
	}
	if(!flag||(fa==-1&&flag==1)){
		if(k1==-1) k1=k2=a;
		else{
			k2=a;
		}
	}
	return ;
}
void link_all(int n)
{
	int last=-1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			k1=k2=-1;
			dfs2(i,-1);
			if(last==-1){
				
			}else{
				_add(last,k1);
			}
			last=k2;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		init(n);
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);
			du[a]++;
			du[b]++;
		}
		dfs(1,-1);
		dfs1(1,-1,0);
		link_all(n);
		cout<<ans[0].size()<<endl;
		for(int i=0;i<ans[0].size();i++){
			for(int j=0;j<4;j++){
				cout<<ans[j][i]<<(j==4-1?"":" ");
			}
			cout<<endl;
		}
	}
	return 0;
}