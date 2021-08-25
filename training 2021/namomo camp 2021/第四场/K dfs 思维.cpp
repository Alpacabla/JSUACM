#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],vise[max_n<<1];
inline void add(int a,int b){
	static int tot=1;
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
bool vis[max_n];
vector<tuple<int,int,int> > ans;
void dfs(int a,int pa)
{
	int fa=0;
	vis[a]=true;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]){
			dfs(u,a);
		}
		if(u==pa){
			fa=i;
		}
	}
	int last=0;
	for(int i=head[a];i;i=nxt[i]){
		if(!vise[i]&&i!=fa){
			vise[i]=true;
			vise[i^1]=true;
			if(!last){
				last=to[i];
			}else{
				ans.push_back(make_tuple(last,a,to[i]));
				last=0;
			}
		}
	}
	if(last&&pa&&last!=pa){
		vise[fa]=true;
		vise[fa^1]=true;
		ans.push_back(make_tuple(pa,a,last));
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]) dfs(i,0);
	}
	cout<<ans.size()<<endl;
	for(auto [a,b,c]:ans){
		cout<<a<<" "<<b<<" "<<c<<endl;
	}
	return 0;
}