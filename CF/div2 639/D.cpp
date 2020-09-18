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
bool col[1005],row[1005];
bool colt[1005],rowt[1005];
vector<int> cols,rows;
bool vis[1005][1005];
int sta[4][2]={1,0,-1,0,0,-1,0,1};
string book[1005];
int n,m;
void dfs(int x,int y)
{
	if(x<0||x>=n) return ;
	if(y<0||y>=m) return ;
	if(book[x][y]=='.') return ;
	if(vis[x][y]){
		return ;
	}
	vis[x][y]=true;
	if(!colt[y]){
		colt[y]=true;
		cols.push_back(y);
	}
	
	if(!rowt[x]){
		rowt[x]=true;
		rows.push_back(x);
	}
	
	int i;
	for(i=0;i<4;i++){
		dfs(x+sta[i][0],y+sta[i][1]);
	}
	return ;
}
bool judge()
{
	int i;
	for(i=0;i<cols.size();i++){
		if(col[cols[i]]){
			cout<<cols[i]<<endl;
			return false;
		}
		colt[cols[i]]=false;
	}
	if(i==cols.size()) cols.clear();

	for(i=0;i<rows.size();i++){
		if(row[rows[i]]){
			cout<<rows[i]<<endl;
			return false;
		}
		rowt[rows[i]]=false;
	}
	if(i==rows.size()) rows.clear();
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;

	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>book[i];
	}
	int ans=0;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			if(!vis[i][j]&&book[i][j]=='#'){
				dfs(i,j);
				if(!judge()){
					cout<<-1<<endl;
					exit(0);
				}
				ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}