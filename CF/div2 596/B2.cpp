// Problem: B2. TV Subscriptions (Hard Version)
// Contest: Codeforces - Codeforces Round #596 (Div. 2, based on Technocup 2020 Elimination Round 2)
// URL: https://codeforces.com/contest/1247/problem/B2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
const int max_m=1e6+5;
int vis[max_m];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k,d;
		cin>>n>>k>>d;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			vis[a[i]]=0;
		}
		int min1=0;
		for(int i=1;i<=d;i++){
			if(!vis[a[i]]){
				min1++;
			}
			vis[a[i]]++;
		}
		int v=min1;
		for(int i=d+1;i<=n;i++){
			vis[a[i-d]]--;
			if(vis[a[i-d]]==0){
				v--;
			}
			if(!vis[a[i]]) v++;
			vis[a[i]]++;
			min1=min(min1,v);
		}
		cout<<min1<<endl;
	}
	return 0;
}