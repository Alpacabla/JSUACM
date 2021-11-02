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
int head[max_n],to[max_n*5],nxt[max_n*5],cnt=1;
inline void add(int a,int b){
	nxt[++cnt]=head[a];
	head[a]=cnt;
	to[cnt]=b;
	return ;
}
int dfn[max_n],low[max_n],now=0;
bool in_stack[max_n];
stack<int> stacks;
int ans;
void tarjan(int x)
{
	dfn[x]=low[x]=++now;
	stacks.push(x);
	in_stack[x]=true;
	for(int i=head[x];i;i=nxt[i]){
		if(!dfn[to[i]]){
			tarjan(to[i]);
			low[x]=min(low[x],low[to[i]]);
		}else{
			if(in_stack[to[i]]){
				low[x]=min(low[x],low[to[i]]);
			}
		}
	}
	if(dfn[x]==low[x]){
		bool flag=false;
		while(stacks.top()!=x){
			in_stack[stacks.top()]=false;
			stacks.pop();
			flag=true;
		}
		in_stack[stacks.top()]=false;
		stacks.pop();
		if(flag) ans++;
		// int k=0;
		// while(!stacks.empty()&&low[stacks.top()]==low[x]){
		// 	k++;
		// 	in_stack[stacks.top()]=false;
		// 	stacks.pop();
		// }
		// if(k>1) ans++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	for(i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	while(!stacks.empty()) stacks.pop();
	for(i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	cout<<ans<<endl;
	return 0;
}