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
struct node{
	int x,y;
	node() {}
	node(int a,int b): x(a),y(b) {};
}nodes[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m,t;
	cin>>n>>m>>t;
	for(i=0;i<t;i++){
		int a,b;
		cin>>a>>b;
		nodes[i]=node(a,b);
	}
	bool flag1=false,flag2=false;
	ll ans=0;
	if(t%n==0){
		flag1=true;
		sort(nodes,nodes+t,[](node a,node b) -> bool{
			return a.x<b.x;
		});
		int x=t/n;
		int ind=0;
		for(i=1;i<=n;i++){
			for(j=0;j<x;j++,ind++){
				ans+=min(min((n-node[ind].x+i),node[ind].x+(n-i)),abs(nodes[ind].x-i));
			}
		}
	}
	if(t%m==0){
		flag2=true;
	}
	return 0;
}
