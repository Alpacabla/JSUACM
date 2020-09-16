/*
link: https://www.acwing.com/problem/content/103/
tags: difference greedy easy
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
const int max_n=1e4+5;
int d[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	set<pair<int,int> >sets;
	sets.clear();
	int n,p,h,m;
	cin>>n>>p>>h>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		if(a>b) swap(a,b);
		auto pp=make_pair(a,b);
		if(sets.count(pp)!=1){
			d[a+1]-=1;
			d[b]+=1;
		}
		sets.insert(pp);
	}
	d[0]=h;
	for(i=1;i<=n;i++){
		d[i]+=d[i-1];
		cout<<d[i]<<endl;
	}
	return 0;
}
