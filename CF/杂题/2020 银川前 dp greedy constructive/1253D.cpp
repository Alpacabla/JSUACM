// Problem: D. Harmonious Graph
// Contest: Codeforces - Codeforces Round #600 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1253/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
int pa[max_n];
inline int find(int a){
	return pa[a]?pa[a]=find(pa[a]):a;
}
int head[max_n],to[max_n<<1],nxt[max_n<<1];
int tot=0;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int max1[max_n];
bool vis[max_n];
bool merge(int a,int b){
	a=find(a),b=find(b);
	if(a!=b){
		max1[a]=max(max1[b],max1[a]);
		pa[b]=a;
		return true;
	}
	return false;
}
int root;
vector<int> v;
void dfs(int a)
{
	if(vis[a]) return ;
	vis[a]=true;
	merge(root,a);
	v.push_back(a);
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		dfs(u);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) max1[i]=i;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			root=i;
			v.clear();
			dfs(i);
			//cout<<v.size()<<endl;
		}
	}
	int ans=0;
	int r;
	for(int i=1;i<=n;i++){
		int k=find(i);
		r=max1[k];
		//cout<<r<<endl;
		for(int j=i+1;j<=r;j++){
			int kk=find(j);
			ans+=merge(k,kk);
			k=find(k);
			r=max1[k];
		}
		i=r;
	}
	cout<<ans<<endl;
	return 0;
}