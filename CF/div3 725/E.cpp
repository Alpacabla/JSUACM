// Problem: E. Funny Substrings
// Contest: Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.com/contest/1538/problem/E
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
int check(string s)
{
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		while(n--){
			string s,opt,ss;
			cin>>s>>opt>>ss;
			map<string,pair<string,string> > mp;
			map<string,int> ans;
			map<string,bool> sta;
			if(opt==":="){
				mp[s]=make_pair(ss,ss);
				ans[s]=check(ss);
			}else{
				string k,ad;
				cin>>k>>ad;
				ans[s]=ans[ss]+ans[ad]+check(mp[ss].second+mp[ad].first);
			}
		}
	}
	return 0;
}