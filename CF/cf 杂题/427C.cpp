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
const int max_n=1e5+5;
int head[max_n],to[max_n*3],nxt[max_n*3],v[max_n];
int tot=0;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int low[max_n],dfn[max_n],now=0;
bool insta[max_n];
stack<int>sta;
const ll mod=1e9+7;
ll ans1=0,ans2=1;
void tarjan(int a)
{
	low[a]=dfn[a]=++now;
	insta[a]=true;
	sta.push(a);
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!dfn[u]){
			tarjan(u);
			low[a]=min(low[a],low[u]);
		}else{
			if(insta[u]){
				low[a]=min(low[a],dfn[u]);
			}
		}
	}
	
	if(low[a]==dfn[a]){
		vector<int> con(0);
		int min1=int_inf;
		while(sta.top()!=a){
			int top=sta.top();
			min1=min(v[top],min1);
			con.push_back(top);
			insta[top]=false;
			sta.pop();
		}
		int top=sta.top();
		min1=min(v[top],min1);
		con.push_back(top);
		insta[top]=false;
		sta.pop();
		int cnt=0;
		for(int i=0;i<con.size();i++){
			if(v[con[i]]==min1){
				cnt++;
			}
		}
		ans1+=min1;
		ans2*=cnt;
		ans2%=mod;
	}
	
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}