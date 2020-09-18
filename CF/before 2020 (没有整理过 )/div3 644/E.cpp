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
string s[55];
bool vis[55][55];
int n;
void dfs(int x,int y)
{
	if(x<0||x>=n){
		return ;
	}
	if(y<0||y>=n){
		return ;
	}
	if(s[x][y]=='0'){
		return ;
	}
	if(vis[x][y]){
		return ;
	}
	if(s[x][y]=='1'){
		vis[x][y]=true;
	}

	dfs(x-1,y);
	dfs(x,y-1);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int flag=1;
		for(i=0;i<n;i++){
			cin>>s[i];
			memset(vis[i],false,n+2);
		}
		for(i=0;i<n;i++){
			dfs(n-1,i);
		}
		for(i=0;i<n;i++){
			dfs(i,n-1);
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(s[i][j]=='1'&&!vis[i][j]){
					flag=0;
				}
			}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}