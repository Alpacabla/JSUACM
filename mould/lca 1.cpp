#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int INF=0x3f3f3f3f;
const int max_n=5e5+5;
int fa[24][max_n];
int dep[max_n];
int log_2[max_n];
int head[max_n];
int nxt[max_n*2];
int to[max_n*2];
int cnt;
inline void add_edge(int a,int b){
	nxt[++cnt]=head[a];
	head[a]=cnt;
	to[cnt]=b;
	return ;
}
int LCA(int a,int b)
{
	int d;
	if(dep[a]<dep[b]){
		swap(a,b);
	}
	d=dep[a]-dep[b];
	int x=0;
	while(d){
		if(d&1){
			a=fa[x][a];
		}
		x++;
		d>>=1;
	}
	if(a==b) return a;
	else{
		int i;
		for(i=log_2[dep[a]-1];i>=0;i--){
			if(fa[i][a]!=fa[i][b]){
				a=fa[i][a];
				b=fa[i][b];
			}
		}
		return fa[0][a];
	}
}
void creat_tree(int root,int father)
{
	dep[root]=dep[father]+1;
	int i=0;
	while(i<log_2[dep[root]]){
		fa[i+1][root]=fa[i][fa[i][root]];
		i++;
	}
	for(i=head[root];i;i=nxt[i]){
		int& vertex=to[i];
		if(vertex!=father){
			fa[0][vertex]=root;
			creat_tree(vertex,root);
		}
	}
	return ;
}
int main()
{
	int n,m,root;
	int i,j;
	int a,b;
	scanf("%d%d%d",&n,&m,&root);
	int x=1;
	log_2[0]=-1;
	for(i=1;i<=n;i++){
		if(x!=i) log_2[i]=log_2[i-1];
		else  x<<=1,log_2[i]=log_2[i-1]+1;
	}
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		add_edge(a,b);
		add_edge(b,a);
	}
	fa[0][root]=0;
	dep[0]=-1;
	creat_tree(root,0);
	for(i=0;i<m;i++){
		scanf("%d%d",&a,&b);
		printf("%d\n",LCA(a,b));
	}
	return 0;
}