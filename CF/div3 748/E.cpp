// Problem: E. Gardener and Tree
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
const int max_n=4e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot=1;
inline void add(int a,int b){
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		tot=1;
		vector<int> du(n+1);
		for(int i=1;i<=n;i++) head[i]=0;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			add(a,b);
			add(b,a);
			du[a]++;
			du[b]++;
		}
		if(n==1&&k==1){
			cout<<0<<endl;
			continue;
		}
		vector<int> ans(n+1);
		vector<int> dp(n+1);
		queue<int> sta;
		for(int i=1;i<=n;i++){
			if(du[i]==1){
				//vis[i]=true;
				sta.push(i);
				dp[i]=1;
			}
		}
		while(sta.size()){
			int v=sta.front();
			//cout<<v<<" ";
			sta.pop();
			for(int i=head[v];i;i=nxt[i]){
				int &u=to[i];
				du[u]--;
				if(du[u]==1){
					sta.push(u);
					dp[u]=dp[v]+1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans[dp[i]]++;
		}
		int now=n;
		vector<int> out(n+1);
		for(int i=1;i<=n;i++){
			now-=ans[i];
			out[i]=now;
			if(now==0) break;
		}
		cout<<(k>n?0:out[k])<<endl;
	}
	return 0;
}