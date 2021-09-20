// Problem: A. Regular Bracket Sequences
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/A
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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<string> ans;
		for(int i=0;i<n;i++){
			string s;
			for(int j=0;j<i;j++){
				s+='(';
			}
			for(int j=0;j<i;j++){
				s+=')';
			}
			for(int j=i;j<n;j++){
				s+='(';
			}
			for(int j=i;j<n;j++){
				s+=')';
			}
			ans.push_back(s);
		}
		for(auto a:ans) cout<<a<<endl;
	}
	return 0;
}