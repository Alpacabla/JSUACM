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
vector<int> ans[4];
bool vis[max_n];
inline void init(int n)
{
	memset(vise,0,sizeof(bool)*(2*n+4));
	memset(vis,0,sizeof(bool)*(n+4));
	memset(head,0,sizeof(int)*(n+4));
	memset(du,0,sizeof(int)*(n+4));
	tot=1;
	for(int i=0;i<4;i++) ans[i].clear();
	return ;
}
inline void del(int a,int b){
	ans[0].push_back(a);
	ans[1].push_back(b);
	return ;
}
inline void _add(int a,int b){
	ans[2].push_back(a);
	ans[3].push_back(b);
	return ;
}
void dfs(int a,int fa)
{
	int k;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			dfs(u,a);
		}else{
			k=i;
		}
	}
	if(du[a]>=3&&fa!=-1){
		del(a,fa);
		du[a]--;
		du[fa]--;
		vise[k]=vise[k^1]=true;
	}
	int cnt=0;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vise[i]&&u!=fa){
			cnt++;
			if(cnt>2){
				del(a,u);
				vise[i]=true;
				vise[i^1]=true;
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