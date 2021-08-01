// Problem: B. Two Tables
// Contest: Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1555/problem/B
// Memory Limit: 256 MB
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
		int w,h;
		cin>>w>>h;
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int w1=x2-x1,h1=y2-y1;
		int w2,h2;
		cin>>w2>>h2;
		int ans=int_inf;
		if(w2+w1>w||h1+h2>h){
			if(w2+w1>w&&h1+h2>h){
				cout<<-1<<endl;
				continue;
			}else{
				if(w2+w1>w){
					ans=max(y2+h2-h,0);
					ans=min(ans,max(0-(y1-h2),0));
				}else{
					ans=min(ans,max(x2+w2-w,0));
					ans=min(ans,max(0-(x1-w2),0));
				}
			}
		}else{
			ans=max(y2+h2-h,0);
			ans=min(ans,max(0-(y1-h2),0));
			ans=min(ans,max(x2+w2-w,0));
			ans=min(ans,max(0-(x1-w2),0));
		}
		cout<<ans<<endl;
	}
	return 0;
}