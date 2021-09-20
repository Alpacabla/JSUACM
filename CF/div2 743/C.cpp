// Problem: C. Book
// Contest: Codeforces - Codeforces Round #743 (Div. 2)
// URL: https://codeforces.com/contest/1573/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
const int max_n=2e5+5;
int head[max_n],to[max_n<<1],nxt[max_n<<1],du[max_n],tot=1;
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
		int n;
		cin>>n;
		tot=1;
		for(int i=1;i<=n;i++){
			head[i]=0;
		}
		memset(du,0,sizeof(int)*(n+1));
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			while(k--){
				int a;
				cin>>a;
				add(a,i);
				du[i]++;
			}
		}
		struct node{
			ll t;
			int a;
			bool operator < (const node aa) const {
				return t>aa.t;
			}
		};
		priority_queue<node> q;
		vector<int> vis(n+1);
		for(int i=1;i<=n;i++){
			if(du[i]==0) vis[i]=true,q.push({i-1,i});
			
		}
		int ans=1;
		while(q.size()){
			ll t=q.top().t;
			int a=q.top().a;
			q.pop();
			ans=max(1ll*ans,(t+1+n-1)/n);
			for(int i=head[a];i;i=nxt[i]){
				du[to[i]]--;
				if(du[to[i]]==0){
					vis[to[i]]=true;
					q.push({t%n+1>to[i]?t/n*n+to[i]-1+n:t/n*n+to[i]-1,to[i]});
				}
			}
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				flag=false;
			}
		}
		cout<<(flag?ans:-1)<<endl;
	}
	return 0;
}