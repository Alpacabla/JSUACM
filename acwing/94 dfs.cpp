/*
link: https://www.acwing.com/problem/content/96/
tags: dfs easy
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
int n;
bool vis[15];
int num[15];
inline void pri()
{
	for(int i=0;i<n;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;
}
void permu(int a)
{
	if(a==n){
		pri();
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			num[a]=i;
			permu(a+1);
			vis[i]=false;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	cin>>n;
	int num[15];
	permu(0);
	return 0;
}
