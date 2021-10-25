// Problem: B. Divine Array
// Contest: Codeforces - Codeforces Round #751 (Div. 2)
// URL: https://codeforces.com/contest/1602/problem/B
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int> > a(n+5,vector<int> (n+1));
		for(int i=1;i<=n;i++) cin>>a[0][i];
		for(int i=1;i<=n+3;i++){
			vector<int> vis(n+1);
			for(int j=1;j<=n;j++){
				vis[a[i-1][j]]++;
			}
			for(int j=1;j<=n;j++){
				a[i][j]=vis[a[i-1][j]];
			}
		}
		int q;
		cin>>q;
		while(q--){
			int aa,b;
			cin>>aa>>b;
			cout<<a[min(n+3,b)][aa]<<endl;
		}
	}
	return 0;
}