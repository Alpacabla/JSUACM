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
int head[max_n],to[max_n<<2],nxt[max_n<<2],head1[max_n],tot1=1,tot=1;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
inline void add1(int a,int b){
	to[++tot]=b;
	nxt[tot]=head1[a];
	head1[a]=tot;
	return ;
}
int pa[max_n];
int ans[max_n];
int find(int a){
	return pa[a]?pa[a]=find(pa[a]):a;
}
void merge(int a,int b)
{
	a=find(a),b=find(b);
	if(a==b) return ;
	else{
		pa[a]=b;
		add1(b,a);
		return ;
	}
}
void dfs(int a,int v)
{
	ans[a]=v;
	for(int i=head1[a];i;i=nxt[i]){
		int &u=to[i];
		dfs(u,v+1);
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
		for(int i=1;i<=n;i++){
			ans[i]=0;
			pa[i]=0;
			head[i]=0;
			head1[i]=0;
		}
		tot=1;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			add(u,v);
			add(v,u);
		}
		vector<int> a(n+1),ind(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ind[i]=i;
		}
		sort(ind.begin()+1,ind.end(),[&a](int aa,int bb) -> bool{
			return a[aa]<a[bb];
		});
		for(int o=1;o<=n;o++){
			int &i=ind[o];
			for(int j=head[i];j;j=nxt[j]){
				int &u=to[j];
				int &v=i;
				if(a[v]<a[u]) continue;
				merge(u,v);
			}
		}
		dfs(ind[n],1);
		for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	}
	return 0;
}