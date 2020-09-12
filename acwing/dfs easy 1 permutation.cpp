/*
https://www.acwing.com/problem/content/95/
acwing 95
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
int n,m;
int num[30];
void dfs(int a,int last)
{
	if(a>m){
		for(int i=1;i<=m;i++){
			cout<<(i==1?"":" ")<<num[i];
		}
		cout<<endl;
		return ;
	}
	for(int i=last+1;i<=n;i++){
		num[a]=i;
		dfs(a+1,i);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	cin>>n>>m;
	dfs(1,0);
	return 0;
}