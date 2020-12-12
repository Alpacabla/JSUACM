/*
link: https://vjudge.net/problem/HDU-1079
tags: mex函数模板题，虽然看了眼别人做法都是直接写出规律，好像很简单，呜呜呜，算惹，我是笨逼。
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
int sg[110][13][32];
bool vis[4];
bool leap[110];
int days[13];
int get_sg(int a,int b,int c)
{
	if(sg[a][b][c]!=-1) return sg[a][b][c];
	int aa,bb,cc;
	aa=a,bb=b,cc=c;
	cc++;
	if(leap[aa]) days[2]=29;
	else days[2]=28;
	if(cc>days[bb]){
		bb++;
		cc=1;
		if(bb>12){
			aa++;
			bb=1;
		}
	}
	vis[get_sg(aa,bb,cc)]=true;
	aa=a,bb=b,cc=c;
	bb++;
	if(bb>12) aa++,bb=1;
	if(cc<=days[bb]) vis[get_sg(aa,bb,cc)]=true;
	sg[a][b][c]=0;
	while(vis[sg[a][b][c]]) sg[a][b][c]++;
	vis[0]=vis[1]=vis[2]=vis[3]=false;
	return sg[a][b][c]; 
}
inline void init()
{
	memset(sg,-1,sizeof(sg));
	for(int i=5;i<=30;i++) sg[101][11][i]=2;
	for(int i=1;i<=31;i++) sg[101][12][i]=2;
	sg[101][10][3]=0;
	sg[101][11][2]=0;
	sg[101][11][3]=1;
	sg[101][11][4]=1;
	days[1]=31;
	days[2]=29;
	days[3]=31;
	days[4]=30;
	days[5]=31;
	days[6]=30;
	days[7]=31;
	days[8]=31;
	days[9]=30;
	days[10]=31;
	days[11]=30;
	days[12]=31;
	for(int i=1900;i<=2002;i++){
		if(i%400==0||(i%4==0&&i%100!=0)){
			leap[i-1900]=true;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	init();
	int a,b,c;
	int n;
	cin>>n;
	while(n--){
		cin>>a>>b>>c;
		if(get_sg(a-1900,b,c)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}