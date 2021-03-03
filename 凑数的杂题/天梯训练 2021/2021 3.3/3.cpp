/*
link: 
tags: 
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
//int a[61][1290][1286];
vector<vector<vector<int> > > a;
vector<vector<vector<bool> > > vis;
//bool vis[61][1290][1286];
int sta[6][3]={
	1,0,0,
	-1,0,0,
	0,1,0,
	0,-1,0,
	0,0,1,
	0,0,-1
};
int cnt;
int n,m,l;
inline bool check(int x,int y,int z){
	if(x<1||x>l||y<1||y>n||z<1||z>m) return false;
	if(vis[x][y][z]||a[x][y][z]==0) return false;
	return true;
}
queue<int> aa,bb,cc;
inline void push_all(int x,int y,int z){
	aa.push(x),bb.push(y),cc.push(z);
}
void bfs(int x,int y,int z)
{
	while(aa.size()) aa.pop(),bb.pop(),cc.pop();
	push_all(x,y,z);
	cnt=1;
	vis[x][y][z]=true;
	while(aa.size()){
		int x=aa.front(),y=bb.front(),z=cc.front();
		aa.pop(),bb.pop(),cc.pop();
		for(int i=0;i<6;i++){
			int xx=x+sta[i][0],yy=y+sta[i][1],zz=z+sta[i][2];
			if(check(xx,yy,zz)){
				vis[xx][yy][zz]=true;
				cnt++;
				push_all(xx,yy,zz);
			}
		}
	}
	// vis[x][y][z]=true;
	// cnt++;
	// for(int i=0;i<6;i++){
	// 	int xx=x+sta[i][0],yy=y+sta[i][1],zz=z+sta[i][2];
	// 	if(check(xx,yy,zz)){
	// 		dfs(xx,yy,zz);
	// 	}
	// }
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//int i,j;
	int t;
	cin>>n>>m>>l>>t;
	a.resize(l+1);
	vis.resize(l+1);
	for(int i=1;i<=l;i++){
		a[i].resize(n+1);
		vis[i].resize(n+1);
		for(int j=1;j<=n;j++) a[i][j].resize(m+1),vis[i][j].resize(m+1);
	}
	for(int i=1;i<=l;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				cin>>a[i][j][k];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=l;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(check(i,j,k)){
					cnt=0;
					bfs(i,j,k);
					if(cnt>=t) ans+=cnt;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}