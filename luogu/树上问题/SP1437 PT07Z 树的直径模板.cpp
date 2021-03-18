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
const int max_n=1e4+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1];
int tot;
inline void add(int a,int b)
{
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int dep[max_n];
int max1=0,max2=0;
int ans=-1;
void dfs(int a,int fa)
{
	bool flag=true;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			flag=false;
			dfs(u,a);
			dep[a]=max(dep[a],dep[u]);
		}
	}
	dep[a]+=1;
	max1=0;
	max2=0;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=fa){
			if(dep[u]>=max1){
				max2=max1;
				max1=dep[u];
			}else{
				if(dep[u]>max2){
					max2=dep[u];
				}
			}
		}
	}
	ans=max(ans,max1+max2);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	while(--n){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	dfs(1,-1);
	cout<<ans<<endl;
	return 0;
}