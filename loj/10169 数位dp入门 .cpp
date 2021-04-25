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
vector<ll> dp[20][20];
vector<ll> DIG;
ll xx[20];
ll num;
vector<ll> EMPTY(10,0);
vector<ll> dfs(int now,int dig,bool flag)
{
	if(now>DIG.size()) return EMPTY;
	if(dig!=12&&dp[now-1][dig].size()!=0&&!flag) return dp[now-1][dig];
	int lim=flag?DIG[now]:9;
	vector<ll> res(10);
	if(dig!=12){
		if(!flag) res[dig]=xx[(DIG.size())-now];
		else res[dig]=(num%xx[(DIG.size())-now])+1;
	}
	for(int i=0;i<=lim;i++){
		vector<ll> zz=dfs(now+1,(i==0&&dig==12)?12:i,flag&&i==lim);
		for(int j=0;j<10;j++){
			res[j]+=zz[j];
		}
	}
	if(!flag&&dig!=12){
		dp[now-1][dig]=res;
	}
	return res;
}
void init(ll k)
{
	num=k;
	DIG.clear();
	stack<ll> sta;
	while(k){
		sta.push(k%10);
		k/=10;
	}
	DIG.push_back(-1);
	while(sta.size()){
		DIG.push_back(sta.top());
		sta.pop();
	}
	for(int i=0;i<20;i++){
		for(int j=0;j<20;j++){
			dp[i][j].resize(0);
		}
	}
	xx[0]=1;
	for(int i=1;i<=18;i++){
		xx[i]=xx[i-1]*10;
	}
	vector<ll> res(10,0);
	for(int i=0;i<10;i++){
		res[i]=1;
		if(i!=0) res[i-1]=0;
		dp[DIG.size()-1][i]=res;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a,b;
	cin>>a>>b;
	init(b);
	vector<ll> res=dfs(1,12,true);
	vector<ll> res2(10,0);
	if(a!=1){
		init(a-1);
		res2=dfs(1,12,true);
	}
	for(int i=0;i<10;i++) cout<<res[i]-res2[i]<<" ";
	cout<<endl;
	return 0;
}