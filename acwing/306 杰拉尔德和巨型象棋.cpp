/*
link: https://www.acwing.com/problem/content/308/
tags: 计数类dp，关键是该怎么不遗漏不重复的枚举所有情况 （蓝书
	  这题中用 dp[i] 表示排序后到i这个黑点的所有情况，但是不经过前面所有黑点
	  对于这个值可以用之前的 dp 值来求个对立事件就行了
	  可以想到这是不遗漏不重复的
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
const int max_n=2e5+5;
ll x[max_n],invx[max_n];
ll mod=1e9+7;
ll dp[2005];
struct node{
	int x,y;
	bool operator < (const node &c){
		if(x==c.x) return y<c.y;
		else return x<c.x;
	}
}nodes[2005];
ll qpow(ll a,int b)
{
	ll res=1;
	while(b){
		if(b&1){
			res=res*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
inline ll C(int a,int b)
{
	if(a<b||a<0||b<0) return 0;
	return x[a]*invx[b]%mod*invx[a-b]%mod;
}
void init(int n)
{
	invx[0]=x[0]=1;
	for(int i=1;i<=n;i++){
		x[i]=x[i-1]*i%mod;
		invx[i]=qpow(x[i],mod-2);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int h,w;
	int n;
	cin>>h>>w>>n;
	init(h+w);
	nodes[0].x=nodes[0].y=1;
	for(int i=1;i<=n;i++){
		cin>>nodes[i].x>>nodes[i].y;
	}
	sort(nodes+1,nodes+n+1);
	dp[0]=1;
	nodes[n+1].x=h,nodes[n+1].y=w;;
	for(int i=1;i<=n+1;i++){
		dp[i]=C(nodes[i].x+nodes[i].y-2,nodes[i].x-1);
		int &x=nodes[i].x,&y=nodes[i].y;
		for(int j=1;j<i;j++){
			if(nodes[j].y<=nodes[i].y){
				dp[i]-=dp[j]*C(x+y-nodes[j].x-nodes[j].y,x-nodes[j].x)%mod;
				dp[i]%=mod;
			}
		}
	}
	if(dp[n+1]<0) dp[n+1]+=mod;
	cout<<dp[n+1]<<endl;
	return 0;
}