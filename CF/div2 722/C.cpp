// Problem: C. Parsa's Humongous Tree
// Contest: Codeforces - Codeforces Round #722 (Div. 2)
// URL: https://codeforces.com/contest/1529/problem/C
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
const int max_n=1e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot=1;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
ll dp[max_n][2];
ll v[max_n][2];
void dfs(int a,int pa)
{
	dp[a][0]=dp[a][1]=0;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(u!=pa){
			dfs(u,a);
			dp[a][0]+=max(dp[u][1]+abs(v[a][0]-v[u][1]),dp[u][0]+abs(v[a][0]-v[u][0]));
			dp[a][1]+=max(dp[u][1]+abs(v[a][1]-v[u][1]),dp[u][0]+abs(v[a][1]-v[u][0]));
		}
	}
	return ;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		//test case 
		int n;
		scanf("%d",&n);
		tot=1;
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		for(int i=1;i<=n;i++){
			scanf("%lld%lld",v[i]+0,v[i]+1);			
		}
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			add(a,b);
			add(b,a);
		}
		//cout<<"k"<<endl;
		dfs(1,0);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
	}
	return 0;
}