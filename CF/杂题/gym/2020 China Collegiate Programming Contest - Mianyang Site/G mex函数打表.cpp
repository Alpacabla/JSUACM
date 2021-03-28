/*
link: https://codeforces.com/gym/102822/problem/G
tags: mex 函数打表
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
int mex[59][59][59][59];
bool vis[100];
int dfs(int a,int b,int c,int d)
{
	int sg=mex[a][b][c][d];
	if(sg!=-1) return sg;
	if((a==0&&b==0)||(a+b+c+d)<2){
		return mex[a][b][c][d]=0;
	}
	vector<bool> vis(105);
	if(a>=1&&(b||c||d)){
		vis[dfs(a-1,b,c,d)]=true;
	}
	if(b&&c){
		vis[dfs(a,b-1,c-1,d+1)]=true;
	}
	if(b>=2){
		vis[dfs(a,b-2,c+1,d)]=true;
	}
	int max1=0;
	while(vis[max1]) max1++;
	return mex[a][b][c][d]=max1;
}
bool show[50][50][50];
void init()
{
	memset(mex,-1,sizeof(mex));
	mex[0][0][0][0]=0;
	for(int i=0;i<=8;i++){
		for(int j=0;j<=8;j++){
			for(int k=0;k<=8;k++){
				for(int l=0;l<=8;l++){
					dfs(i,j,k,l);
					if(mex[i][j][k][l]==0&&!show[i][j][k]){
						cout<<i<<" "<<j<<" "<<k<<" "<<dfs(i,j,k,l)<<endl;
						show[i][j][k]=true;
					}
				}
			}
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	init();
	//做就算了，不做了，主要是打表打错了最开始呜呜呜
	// cin>>t;
	// while(t--){
	// 	int n;

	// }
	return 0;
}