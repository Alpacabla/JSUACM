/*
link: 
tags: 
*/
#include<string>
#include<iostream>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
string s[105];
bool vis[105][105];
int n,m;
int sta[8][2]={
	1,1,
	1,0,
	1,-1,
	0,1,
	0,-1,
	-1,1,
	-1,0,
	-1,-1
};
void dfs(int x,int y)
{
	if(x<0||x>=n){
		return ;
	}
	if(y<0||y>=m){
		return ;
	}
	if(vis[x][y]){
		return ;
	}
	if(s[x][y]=='.'){
		return ;
	}
	vis[x][y]=true;
	for(int i=0;i<8;i++){
		int xx=x+sta[i][0],yy=y+sta[i][1];
		dfs(xx,yy);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(!vis[i][j]&&s[i][j]!='.'){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}