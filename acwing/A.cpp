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
int head[max_n],to[max_n],nxt[max_n],ind;
inline void add(int v,int a,int b)
{
	to[++ind]=b;
	nxt[ind]=head[a];
	head[a]=ind;
	val[ind]=v;
	return ;
}
ll ans;
vecor<int> vals;
void dfs(int a)
{
	for(int i=head[a];i;i=nxt[i]){
		vals.push_back(val[i]);
		dfs(to[i]);
		if(a==1){
			ll sum=0;
			for(int j=0;j<vals.size();j++){
				sum+=vals[j];
			}
			ll ave=sum/vals.size();
			for(int j=0;j<vals.size();j++){
				kl
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
	int n,m;
	cin>>n>>m;
	ind=1;
	for(i=0;i<m;i++){
		int a,b,v;
		cin>>a>>b>>v;
		add(v,a,b);
	}
	ans=0;
	dfs(1);
	return 0;
}
