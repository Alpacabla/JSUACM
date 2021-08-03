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
	int x1,x2,y1,y2;
	bool operator < (const node a) const{
		return x1<a.x1;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,d;
	cin>>n>>d;
	vector<node> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2;
	}
	vector<node> aa;
	for(int i=1;i<=n;i++){
		if()
	}


	return 0;
}