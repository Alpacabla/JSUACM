/*
link: https://www.acwing.com/problem/content/description/221/
tags: 这题是裸SG函数，但是关键在于题目中的最后一步是胜利所以不符合有向图游戏中sg函数的定义
	  就不能用sg 异或 表示此局面多个有向图游戏的结果了，必须回退一步，找到最后的必败态，并且要注意
	  不能让sg函数访问到1 1的sg，然后此局面的最终结果是所有情况的sg值取mex
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
int sg[205][205];
int get_sg(int n,int m)
{
	if(sg[n][m]!=-1) return sg[n][m];
	if(sg[m][n]!=-1) return sg[m][n];
	set<int> mex;
	for(int i=2;i<=n-2;i++){
		int a=get_sg(i,m),b=get_sg(n-i,m);
		mex.insert(a^b);
	}
	for(int i=2;i<=m-2;i++){
	    int a=get_sg(n,i),b=get_sg(n,m-i);
		mex.insert(a^b);
	}
	int now=0;
	for(auto a:mex){
		if(now!=a) break;
		else now++;
	}
	return sg[n][m]=now;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	memset(sg,-1,sizeof(sg));
	sg[1][1]=1;
	sg[2][2]=0;
	sg[2][3]=0;
	sg[3][2]=0;
	while(cin>>n>>m){
		if(get_sg(n,m)) cout<<"WIN"<<endl;
		else cout<<"LOSE"<<endl;
	}
	return 0;
}