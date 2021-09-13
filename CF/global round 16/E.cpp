// Problem: E. Buds Re-hanging
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/E
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
const int max_n=2e5+5;
ll ans=0;
int cntcnt=0;
vector<int> e[max_n];
bool dfs(int a,int fa)
{
	int cnt=0;
	for(int i=0;i<e[a].size();i++){
		int &u=e[a][i];
		if(u!=fa){
			cnt+=dfs(u,a);
		}
	}
	if(cnt==1){
		return false;
	}
	if(cnt>1){
		ans+=cnt;
		cntcnt++;
		return false;
	}
	return true;
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
		for(int i=1;i<=n;i++) e[i].clear();
		while(--n){
			int a,b;
			cin>>a>>b;
			e[a].push_back(b);
			e[b].push_back(a);
		}
		ans=0;
		cntcnt=0;
		dfs(1,0);
		if(cntcnt){
			ans-=cntcnt-1;
		}
		cout<<max(ans,1ll)<<endl;
	}
	return 0;
}