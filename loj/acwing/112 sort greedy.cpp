/*
link: https://www.acwing.com/problem/content/description/114/
tags: greedy sort 为了尝试构造函数乱写了一堆
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
const int max_n=1e3+5;
int x[max_n],y[max_n];
struct node{
	double x1,x2;
	node(pair<double,double> a): x1(a.first), x2(a.second){}
	node(){}
}nodes[max_n];
pair<double,double> get_pair(int x,int y,const int d)
{
	double x1,x2;
	x1=sqrt(1.0*d*d-1.0*y*y)+x;
	x2=-sqrt(1.0*d*d-1.0*y*y)+x;
	if(x1>x2){
		swap(x1,x2);
	}
	return make_pair(x1,x2);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,d;
	bool flag=true;
	cin>>n>>d;
	for(i=0;i<n;i++){
		cin>>x[i]>>y[i];
		if(y[i]>d) flag=false;
	}
	if(!flag) cout<<-1<<endl;
	else{
		for(i=0;i<n;i++){
			nodes[i]=node(get_pair(x[i],y[i],d));
		}
		sort(nodes,nodes+n,[](node a,node b) -> bool {
			return a.x2<b.x2;
		});
		int ans=1;
		double r=nodes[0].x2;
		for(i=0;i<n;i++){
			if(nodes[i].x1>r){
				r=nodes[i].x2;
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
