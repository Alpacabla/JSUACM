// Problem: D. Power Products
// Contest: Codeforces - Codeforces Round #596 (Div. 2, based on Technocup 2020 Elimination Round 2)
// URL: https://codeforces.com/contest/1247/problem/D
// Memory Limit: 512 MB
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
const int max_n=1e5+5;
vector<pair<int,int> > fac[max_n];
bool vis[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	
	for(int i=2;i<=1e5;i++){
		if(!vis[i]){
			for(int j=i;j<=1e5;j+=i){
				vis[j]=true;
				int v=j;
				int cnt=0;
				while(v%i==0){
					v/=i;
					cnt++;
				}
				if((cnt%=k)!=0) fac[j].push_back({i,cnt});
			}
		}
	}
	ll ans=0;
	map<vector<pair<int,int> >,int> mp;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		vector<pair<int,int> > vv; 
		vv=fac[a];
		for(int i=0;i<vv.size();i++) vv[i].second=k-vv[i].second;
		ans+=mp[vv];
		mp[fac[a]]++;
	}
	cout<<ans<<endl;
	return 0;
}