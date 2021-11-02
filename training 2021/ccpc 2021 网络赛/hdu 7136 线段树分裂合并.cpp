#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
//#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],head1[max_n],tot=1;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int pa[max_n];
int ans[max_n];
int roots[max_n];
int lson[max_n<<5],rson[max_n<<5];
int sum[max_n<<5];
int tot1;
inline void newnode(int &a){
	a=++tot1;
	sum[a]=0;
	lson[a]=rson[a]=0;
	return ;
}
void ins(int &now,int val,int l,int r)
{
	if(!now){
		newnode(now);
	}
	if(l==r){
		//sum[now]=1;
		return ;
	}
	int mid=(l+r)>>1;
	if(val<=mid) ins(lson[now],val,l,mid);
	else ins(rson[now],val,mid+1,r);
	return ;
}
void push_down(int a)
{
	sum[lson[a]]+=sum[a];
	sum[rson[a]]+=sum[a];
	sum[a]=0;
	return ;
}
void mer(int &a,int b)
{
	if(!a||!b){
		a=!a?b:a;
		return ;
	}
	push_down(a);
	push_down(b);
	mer(lson[a],lson[b]);
	mer(rson[a],rson[b]);
	return ;
}
int find(int a){
	return pa[a]?pa[a]=find(pa[a]):a;
}
void merge(int a,int b)
{
	a=find(a),b=find(b);
	if(a==b) return ;
	else{
		pa[a]=b;
		mer(roots[b],roots[a]);
		return ;
	}
}
void dfs(int a,int l,int r)
{
	if(l==r){
		ans[l]=sum[a];
		return ;
	}
	push_down(a);
	int mid=(l+r)>>1;
	dfs(lson[a],l,mid);
	dfs(rson[a],mid+1,r);
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
			roots[i]=0;
		}
		tot=tot1=1;
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
			ins(roots[i],i,1,n);
			for(int j=head[i];j;j=nxt[j]){
				int &u=to[j];
				int &v=i;
				if(a[v]<a[u]) continue;
				merge(u,v);
			}
			sum[roots[i]]=1;
		}
		dfs(roots[ind[n]],1,n);
		for(int i=1;i<=n;i++) cout<<ans[i]<<endl;
	}
	return 0;
}