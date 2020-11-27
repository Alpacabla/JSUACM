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
const int max_n=2e5+5;
int head[max_n],nxt[max_n<<1],to[max_n<<1];
int zzz;
inline void add(int a,int b)
{
	nxt[++zzz]=head[a];
	to[zzz]=b;
	head[a]=zzz;
	return ;
}
vector<int> con;
bool vis[max_n];
ll ans=0;
int dfn[max_n],low[max_n];
int tot;
stack<int> sta;
ll cnt=0;
void ddfs(int a,int pa)
{
	cnt++;
	//vis[a]=true;
	for(int i=head[a];i;i=nxt[i]){
		if(!vis[to[i]]&&to[i]!=pa){
			ddfs(to[i],a);
		}
	}
	return ;
}
void dfs(int a,int pa)
{
	sta.push(a);
	dfn[a]=low[a]=++tot;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u==pa) continue;
		if(!dfn[u]){
			dfs(u,a);
			low[a]=min(low[a],low[u]);
		}else{
			low[a]=min(low[a],dfn[u]);
		}
	}
	if(dfn[a]==low[a]){
		int v=low[a];
		vector<int> t(0);
		while(sta.size()&&low[sta.top()]==v){
			t.push_back(sta.top());
			sta.pop();
		}
		if(t.size()>1){
			con=t;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		zzz=0;
		cin>>n;
		for(int i=1;i<=n;i++) head[i]=dfn[i]=low[i]=vis[i]=0;
		for(int i=1;i<=n;i++){
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);
		}
		while(sta.size()) sta.pop();
		tot=0;
		ans=1ll*(n-1)*n/2;
		con.clear();
		dfs(1,-1);
		for(int i=0;i<con.size();i++){
			vis[con[i]]=true;
		}
		ll last=0;
		for(int i=0;i<con.size();i++){
			cnt=0;
			ddfs(con[i],-1);
			ans+=last*cnt;
			last+=cnt;
		}
		cout<<ans<<endl;
	}
	return 0;
}