// Problem: A. Distance
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1612/problem/A
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
		int x,y;
		cin>>x>>y;
		int d=x+y;
		bool flag=true;
		int ans1=-1,ans2=-1;
		for(int i=0;i<=55&&flag;i++){
			for(int j=0;j<=55&&flag;j++){
				int k1=i+j;
				int k2=abs(i-x)+abs(j-y);
				if(k1*2==d&&k2*2==d){
					ans1=i,ans2=j;
					flag=false;
				}
			}
		}
		cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}