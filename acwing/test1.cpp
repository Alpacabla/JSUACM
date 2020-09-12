/*
https://codeforces.ml/gym/294361/problem/K
bfs graph
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
int head[max_n],to[max_n],nxt[max_n],ind;
inline void add(int a,int b){
	to[++ind]=b;
	nxt[ind]=head[a];
	head[a]=ind;
	return ;
}
int vis[max_n],from[max_n];
void bfs(int s)
{
	queue<int> q;
	queue<int> qq;
	while(!q.empty()) q.pop();
	while(!qq.empty()) qq.pop();
	//q.push(s);
	//qq.push(s);
	for(int i=head[s];i;i=nxt[i]){
		q.push(to[i]);
		qq.push(to[i]);
		from[to[i]]=to[i];
		vis[to[i]]=1;
	}
	vis[s]=2;
	while(!q.empty()){
		int t=q.front(),tt=qq.front();
		q.pop(),qq.pop();
		for(int i=head[t];i;i=nxt[i]){
			if(vis[to[i]]!=2){
				//cout<<to[i]<<endl;
				//cout<<vis[to[i]]<<endl;
				if(vis[to[i]]){
					if(tt!=from[to[i]]){
						vis[to[i]]++;
						q.push(to[i]);
						qq.push(tt);
					}
				}else{
					vis[to[i]]++;
					from[to[i]]=tt;
					q.push(to[i]);
					qq.push(tt);
				}
			}
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m,t;
	cin>>n>>m>>t;
	ind=0;
	for(i=0;i<n;i++) from[i]=-1;
	for(i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		add(b,a);
	}
	bfs(t);
	vector<int>ans;
	ans.clear();
	for(i=head[t];i;i=nxt[i]){
		if(vis[to[i]]!=2){
			vis[to[i]]=3;
		}
	}
	for(i=0;i<n;i++){
		if(vis[i]==3){
			ans.push_back(i);
		}
	}
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}