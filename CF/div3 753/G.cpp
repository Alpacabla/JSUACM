// Problem: G. Banquet Preparations 1
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		ll max1=0,min1=0;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			int t1,t2;
			//t1=x,t2=y;
			t1=max(0,x-m);
			t2=y-(m-(x-t1));
			int d=t2-t1;
			max1+=d;
			t1=max(0,y-m);
			t2=x-(m-(y-t1));
			d=t2-t1;
			min1-=d;
			if(max1<min1){
				cout<<"u"<<endl;
			}
		}
		if(min1<0&&max1>0) cout<<0<<endl;
		else{
			cout<<min(abs(min1),abs(max1))<<endl;
		}
	}
	return 0;
}