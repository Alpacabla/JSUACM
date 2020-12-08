/*
link: https://www.acwing.com/problem/content/146/
tags: 01trie 树上差分 居然是树上差分呜呜呜
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
const int max_n=1e5+5;
int cnt=1;
int nxt[max_n<<1],head[max_n],to[max_n<<1],v[max_n<<1];
inline void add(int a,int b,int val){
	to[++cnt]=b;
	nxt[cnt]=head[a];
	head[a]=cnt;
	v[cnt]=val;
	return ;
}
int sum[max_n];
void dfs(int a,int pa,int xor_v)
{
	sum[a]=xor_v;
	for(int i=head[a];i;i=nxt[i]){
		if(pa!=to[i]){
			dfs(to[i],a,xor_v^v[i]);
		}
	}
	return ;
}
int trie[max_n<<4][2];
void insert(int val)
{
	int now=0;
	static int tot=0;
	for(int i=30;i>=0;i--){
		int k=(val>>i)&1;
		now=(trie[now][k]?trie[now][k]:(trie[now][k]=++tot));
	}
	return ;
}
int check(int val)
{
	int res=0;
	int now=0;
	for(int i=30;i>=0;i--){
		int k=(val>>i)&1^1;
		if(trie[now][k]) now=trie[now][k],res+=(1<<i);
		else now=trie[now][!k];
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,root;
	cin>>n;
	for(int i=1;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
		root=a;
	}
	dfs(root,-1,0);
	int ans=-1;
	for(int i=0;i<n;i++){
		insert(sum[i]);
		ans=max(ans,check(sum[i]));
	}
	cout<<ans<<endl;
	return 0;
}