// Problem: E. Trees of Tranquillity
// Contest: Codeforces - Codeforces Round #722 (Div. 2)
// URL: https://codeforces.com/contest/1529/problem/E
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
const int max_n=3e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot=1,head1[max_n];
inline void add(int *head,int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
pair<int,int> dfn[max_n];
pair<int,int> last[max_n];
int timer=0;

void dfs1(int a)
{
	dfn[a].first=++timer;
	for(int i=head1[a];i;i=nxt[i]){
		int &u=to[i];
		dfs1(u);
	}
	dfn[a].second=timer;
	return ;
}
set<pair<int,int> >sets;
int ans,cnt;
int addnode(int a)
{
	int &in=dfn[a].first,&out=dfn[a].second;
	auto k=sets.upper_bound(dfn[a]);
	bool flag=true;
	if(k==sets.end()||!(k->first<=in&&k->second>=out)) k=prev(k);
	if(k->first<=in&&k->second>=out){
		last[a]=*k;
		sets.erase(k);
		sets.insert(dfn[a]);
		return 0;
	}else{
		sets.insert(dfn[a]);
		return 1;
	}
}
int delnode(int a)
{
	int &in=dfn[a].first,&out=dfn[a].second;
	sets.erase(dfn[a]);
	if(last[a].first!=0){
		sets.insert(last[a]);
		last[a].first=0;
		return 0;
	}else{
		return 1;
	}
}
void dfs(int a)
{
	cnt+=addnode(a);
	ans=max(ans,cnt);
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		dfs(u);
	}
	cnt-=delnode(a);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	sets.insert(make_pair(0,0));
	
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		timer=0;
		tot=1;
		memset(head,0,sizeof(int)*(n+2));
		memset(head1,0,sizeof(int)*(n+2));
		
		for(int i=2;i<=n;i++){
			int a;
			cin>>a;
			add(head,a,i);
		}
		for(int i=2;i<=n;i++){
			int a;
			cin>>a;
			add(head1,a,i);
		}
		
		cnt=ans=0;
		dfs1(1);
		dfs(1);
		cout<<ans<<endl;
	}
	return 0;
}