// Problem: C. Robot Collisions
// Contest: Codeforces - Educational Codeforces Round 109 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1525/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> a(n+1),ans(n+1,-1),ind(n+1);
		vector<char> sta(n+1);
		vector<bool> vis(n+1);
		for(int i=1;i<=n;i++) ind[i]=i;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>sta[i];
		sort(ind.begin()+1,ind.end(),[&a](const int b,const int bb) -> bool{
			return a[b]<a[bb];
		});
		stack<int> last[2];
		for(int o=1;o<=n;o++){
			int i=ind[o];
			if(sta[i]=='L'){
				if(last[a[i]%2].size()){
					int j=last[a[i]%2].top();
					last[a[i]%2].pop();
					vis[j]=true;
					vis[i]=true;
					ans[j]=ans[i]=(a[i]-a[j])/2;
				}
			}else{
				last[a[i]%2].push(i);
			}
		}
		while(last[0].size()) last[0].pop();
		while(last[1].size()) last[1].pop();
		for(int o=n;o>=1;o--){
			int i=ind[o];
			if(!vis[i]&&sta[i]=='R'){
				if(last[a[i]%2].size()){
					int j=last[a[i]%2].top();
					last[a[i]%2].pop();
					vis[j]=true;
					vis[i]=true;
					ans[j]=ans[i]=((m-a[j])+(m-a[i]))/2;
				}else{
					last[a[i]%2].push(i);
				}
			}
		}
		
		stack<int> _last[2];
		for(int o=1;o<=n;o++){
			int i=ind[o];
			if(!vis[i]&&sta[i]=='L'){
				if(_last[a[i]%2].size()){
					int j=_last[a[i]%2].top();
					_last[a[i]%2].pop();
					vis[j]=true;
					vis[i]=true;
					ans[j]=ans[i]=(a[j]+a[i])/2;
				}else{
					_last[a[i]%2].push(i);
				}
			}
		}
		
		if(_last[0].size()&&last[0].size()){
			int i=last[0].top(),j=_last[0].top();
			vis[i]=vis[j]=true;
			ans[i]=ans[j]=((m-a[i])+a[j]+m)/2;
		}
		if(_last[1].size()&&last[1].size()){
			int i=last[1].top(),j=_last[1].top();
			vis[i]=vis[j]=true;
			ans[i]=ans[j]=((m-a[i])+a[j]+m)/2;
		}
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<(i==n?"":" ");
		}
		cout<<endl;
	}
	return 0;
}