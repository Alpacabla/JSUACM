// Problem: D2. Seating Arrangements (hard version)
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/D2
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
		
		int tot=0;
		vector<int> a(n*m+1);
		vector<int> z(n*m+1);
		
		
		tot=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[tot];
				z[tot]=a[tot];
				tot++;
			}
		}
		sort(z.begin()+1,z.end());
		
		tot=1;
		vector<vector<pair<int,int> > > coor(n*m+1);
		vector<int> ind(n*m+1);
		tot=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int v=(int)(lower_bound(z.begin()+1,z.end(),z[tot])-z.begin());
				coor[v].push_back({i,j});
				tot++;
			}
		}
		for(int i=1;i<=n*m;i++){
			sort(coor[i].begin(),coor[i].end(),[](pair<int,int> a,pair<int,int> b) ->bool{
				if(a.first==b.first) return a.second>b.second;
				else return a.first<b.first;
			});
		}
		ll ans=0;
		vector<vector<int> >val(n+1);//vis(n+1);
		for(int i=1;i<=n;i++) val[i].resize(m+1);//vis[i].resize(m+1);
		for(int i=1;i<=n*m;i++){
			int v=(int)(lower_bound(z.begin()+1,z.end(),a[i])-z.begin());
			int zzz=ind[v]++;
			for(int j=1;j<coor[v][zzz].second;j++){
				ans+=val[coor[v][zzz].first][j];
			}
			val[coor[v][zzz].first][coor[v][zzz].second]=1;
			//vis[coor[v][zzz].first][coor[v][zzz].second]=i;
		}
		// for(int i=1;i<=n;i++){
			// for(int j=1;j<=m;j++){
				// cout<<vis[i][j]<<" ";
			// }
			// cout<<endl;
		// }
		cout<<ans<<endl;
	}
	return 0;
}