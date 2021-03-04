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
int num[5]={81,27,9,3,1};
char s[5];
int n;
bool flag;
void dfs(int a,int sum)
{
	if(a==5&&sum==n){
		bool vis=false;
		for(int i=0;i<5;i++){
			if(s[i]=='0') continue;
			else if(vis||s[i]!='+') cout<<s[i];
			vis=true;
			cout<<num[i];
		}
		cout<<endl;
		flag=true;
		return ;
	}
	if(a==5) return ;
	if(!flag) s[a]='+',dfs(a+1,sum+num[a]);
	if(!flag) s[a]='-',dfs(a+1,sum-num[a]);
	if(!flag) s[a]='0',dfs(a+1,sum);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	while(cin>>n){
		flag=false;
		dfs(0,0);
	}
	return 0;
}