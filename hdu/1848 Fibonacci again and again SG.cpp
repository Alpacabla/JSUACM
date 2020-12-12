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
int fib[100];
int sg[1005];
int get_sg(int a)
{
	if(sg[a]!=-1) return sg[a];
	bool vis[105]={0};
	for(int i=1;fib[i]<=a;i++){
		vis[get_sg(a-fib[i])]=true;
	}
	sg[a]=0;
	while(vis[sg[a]]) sg[a]++;
	return sg[a];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int a,b,c;
	int k;
	fib[0]=1;
	fib[1]=1;
	for(int i=2;fib[i-1]<=1000;i++){
		fib[i]=fib[i-1]+fib[i-2];
		k=i;
	}
	memset(sg,-1,sizeof(sg));
	sg[0]=0;
	while(cin>>a>>b>>c&&(a||b||c)){
		int ans=get_sg(a)^get_sg(b)^get_sg(c);
		if(ans) cout<<"Fibo"<<endl;
		else cout<<"Nacci"<<endl;
	}
	return 0;
}