// Problem: C. Ticks
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/C
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
		int n,m,d;
		cin>>n>>m>>d;
		vector<string> s(n+1);
		for(int i=1;i<=n;i++){
			cin>>s[i];
			s[i]=' '+s[i];
		}
		vector<vector<int> > vis(n+1,vector<int> (m+1));
		
		auto judge = [&n,&m,&s] (int x,int y) -> bool{
			if(x<1||x>n||y<1||y>m||s[x][y]=='.') return true;
			else return false;  
		};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]=='*'){
					vector<pair<int,int> > a;
					a.push_back({i,j});
					int v=d;
					for(int k=1;;k++){
						int x=i-k,y1=j-k,y2=j+k;
						if(judge(x,y1)||judge(x,y2)){
							break;
						}else{
							v--;
							a.push_back({x,y1});
							a.push_back({x,y2});
						}
					}
					if(v<=0){
						//cout<<"2"<<endl;
						for(auto [c,d]:a){
							//cout<<c<<" "<<d<<endl;
							vis[c][d]=true;
						}
					}
				}
			}
		}
		bool flag=true;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]=='*'&&vis[i][j]==0) flag=false; 
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}