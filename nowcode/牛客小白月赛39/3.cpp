/*
link: 
tags: 
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	strut node{
		int x,y;
		node operator + (node t){
			return {t.x+x,t.y+y};
		} 
	};
	cin>>n;
	vector<node> v;
	for(int i=1;i<=n;i++){
		int x,y,xx,yy;
		cin>>x>>y>>xx>>yy;
		v.push_back({xx-x,yy-y});
	}
	bool flag=false;
	node r;
	for(int i=1;i<=1;i++){
		int x,y,xx,yy;
		cin>>x>>y>>xx>>yy;
		r={xx-x,yy-y};
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			node t=v[i]+v[j];
			if(t.x*r.y==t.y*r.x){
				flag=true;
			}
		}
	}
	cout<<(flag?"YES":"NO")<<endl;
	return 0;
}