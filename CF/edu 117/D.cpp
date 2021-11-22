// Problem: D. X-Magic Pair
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1612/problem/D
// Memory Limit: 512 MB
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
	int  t;
	cin>>t;
	while(t--){
		ll a,b,x;
		cin>>a>>b>>x;
		bool flag=true;
		if(a<b) swap(a,b);
		while(flag){
			if(a<b) swap(a,b);
			if(a==x||b==x){
				flag=false;
				break;
			}
			if(b==0) break;
			if((a-x)%b==0&&a-x>=0){
				flag=false;
				break;
			}
			a=a%b;
		}
		cout<<(!flag?"YES":"NO")<<endl;
	}
	return 0;
}