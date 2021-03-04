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
int num[25][25];
bool vis[25][25];
int now;
int n;
inline bool check(int x,int y){
	return x<=n&&x>=1&&y<=n&&y>=1&&!vis[x][y];
}
int cnt;
void dfs(int a,int x,int y)
{
	if(cnt==2) return ;
	a%=3;
	num[x][y]=now++;
	vis[x][y]=true;
	
	if(a==0){
		if(check(x,y+1)) {cnt=0;dfs(a,x,y+1);}
		else{
			cnt++;
			now--;
			dfs(a+1,x,y);
		}
	}
	if(a==1){
		if(check(x+1,y-1)) {cnt=0;dfs(a,x+1,y-1);}
		else{
			cnt++;
			now--;
			dfs(a+1,x,y);
		}
	}
	if(a==2){
		if(check(x-1,y)) {cnt=0;dfs(a,x-1,y);}
		else{
			cnt++;
			now--;
			dfs(a+1,x,y);
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	while(cin>>n){
		for(int i=1;i<=n;i++){
			memset(vis[i],false,n+2);
		}
		now=1;
		cnt=0;
		dfs(0,1,1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n-i+1;j++){
				cout<<setw(4)<<num[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}