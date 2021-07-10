// Problem: A. Shortest Path with Obstacle
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int x,y;
		int x1,y1;
		int x2,y2;
		cin>>x>>y>>x1>>y1>>x2>>y2;
		int res=abs(x1-x)+abs(y1-y);
		if(x>x1) swap(x,x1);
		if(y>y1) swap(y,y1);
		if((y==y1&&y2==y1)&&(x<x2&&x2<x1)){
			res+=2;
		}else{
			if((x==x1&&x2==x1)&&(y<y2&&y2<y1)){
				res+=2;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}