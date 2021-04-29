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
int a[505][505];
int sta[4][2]={
	0,-1,
	-1,0,
	1,0,
	0,1
};
int lim;
bool vis[505][505];
inline bool judge(int x,int y){
	if((x<=0||x>lim||y<=0||y>lim)) return true;
	if(!vis[x][y]) return true;
	return false;
}
bool flag=true;
int len;
void dfs(int x,int y,int val)
{
	if(judge(x,y)) return ;
	if(a[x][y]&&!flag) return ;
	if(len<=0) return ;
	a[x][y]=val;
	flag=false;
	len--;
	if(len<=0) return ;
	for(int i=0;i<4;i++){
		int xx=x+sta[i][0],yy=y+sta[i][1];
		dfs(xx,yy,val);
	}
	return ;
}
//�������� 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	lim=n;
	for(int i=1;i<=n;i++){
		cin>>a[i][i];
		for(int j=1;j<=i;j++){
			vis[i][j]=true;
		}
	}
	for(int i=1;i<=n;i++){
		len=a[i][i];
		flag=true;
		dfs(i,i,a[i][i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(a[i][j]==0){
				cout<<-1<<endl;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
