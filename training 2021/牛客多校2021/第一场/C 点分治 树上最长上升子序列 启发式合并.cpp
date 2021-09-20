#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1];
void add(int a,int b){
	static int tot=1;
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int val[max_n];
vector<int> f[max_n],g[max_n];
int dp[max_n];
void merge(vector<int> &a,vector<int> &b)
{
	if(a.size()<b.size()){
		swap(a,b);
	}
	for(int i=0;i<b.size();i++){
		a[i]=min(a[i],b[i]);
	}
	return ;
}
bool vis[max_n];
int siz[max_n];
int minsiz=int_inf;
int cen;
void dfs1(int a,int fa)
{
	siz[a]=1;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa&&!vis[u]){
			dfs1(u,a);
			siz[a]+=siz[u];
		}
	}
	return ;
}
void dfs2(int a,int fa,int sizsiz)
{
	int maxsiz=0;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa&&!vis[u]){
			dfs2(u,a,sizsiz);
			maxsiz=max(maxsiz,siz[u]);
		}
	}
	maxsiz=max(maxsiz,sizsiz-siz[a]);
	if(maxsiz<minsiz){
		minsiz=maxsiz;
		cen=a;
	}
	return ;
}
int ans=int_inf;
void ins(vector<int> &a,int val)
{
	auto k=lower_bound(a.begin(),a.end(),val);
	if(k==a.end()) a.push_back(val);
	else *k=val;
	return ;
}
int vv;
void getdp(int a,int fa)
{
	f[a].resize(0);
	g[a].resize(0);
	int res=0;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			getdp(u,a);
			
			if(f[a].size()<g[u].size()){
				for(int i=0;i<f[a].size();i++){
					auto k=lower_bound(g[u].begin(),g[u].end(),-f[a][i]);
					res=max(res,int(k-g[u].begin())+i+1+((k!=g[u].begin())&&(f[a][i]<val[a]&&val[a]<-*prev(k))));
				}
			}else{
				for(int i=0;i<g[u].size();i++){
					auto k=lower_bound(f[a].begin(),f[a].end(),-g[u][i]);
					res=max(res,int(k-f[a].begin())+i+1+((k!=f[a].begin())&&(*prev(k)<val[a]&&val[a]<-g[u][i])));
				}
			}
			
			if(f[u].size()<g[a].size()){
				for(int i=0;i<f[u].size();i++){
					auto k=lower_bound(g[a].begin(),g[a].end(),-f[u][i]);
					res=max(res,int(k-g[a].begin())+i+1+((k!=g[a].begin())&&(f[u][i]<val[a]&&val[a]<-*prev(k))));
				}
			}else{
				for(int i=0;i<g[a].size();i++){
					auto k=lower_bound(f[u].begin(),f[u].end(),-g[a][i]);
					res=max(res,int(k-f[u].begin())+i+1+((k!=f[u].begin())&&(*prev(k)<val[a]&&val[a]<-g[a][i])));
				}
			}
			
			merge(f[a],f[u]);
			merge(g[a],g[u]);
		}
	}
	ins(f[a],val[a]);
	ins(g[a],-val[a]);
	vv=max({vv,res,int(g[a].size()),int(f[a].size())});
	return ;
}
void dfz(int a)
{
	minsiz=int_inf;
	dfs1(a,0);
	dfs2(a,0,siz[a]);
	if(vis[cen]) return ;
	int res=0;
	int toto=0;
	int vvv=0;
	for(int i=head[cen];i;i=nxt[i]){
		int &u=to[i];
		//if(!vis[u]){  不需要vis这里
			vv=0;
			getdp(u,cen);
			if(vvv<vv){
				vvv=vv;
				toto=u;
			}
		//}
	}
    assert(toto!=0);
    ans=min(ans,vvv);
	if(vis[toto]) return ;
	vis[cen]=true;
	dfz(toto);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	for(int i=1;i<=n;i++) cin>>val[i];
	
	dfz(1);
	cout<<ans<<endl;
    assert(ans!=0);
	return 0;
}