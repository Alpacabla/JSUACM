// Problem: A. Fair Playoff
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/A
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
		vector<int> a(4);
		for(int i=0;i<4;i++){
			cin>>a[i];
		}
		vector<int> t;
		t=a;
		sort(a.begin(),a.end());
		vector<int> max1={max(t[0],t[1]),max(t[2],t[3])};
		if(max1[0]<max1[1]) swap(max1[0],max1[1]);
		if(max1[0]==a[3]&&max1[1]==a[2]) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}