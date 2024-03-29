// Problem: A. Domino Disaster
// Contest: Codeforces - Codeforces Round #742 (Div. 2)
// URL: https://codeforces.com/contest/1567/problem/A
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
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
		int n;
		cin>>n;
		string s;
		cin>>s;
		string ans=s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='D') ans[i]='U';
			if(s[i]=='U') ans[i]='D';
		}
		cout<<ans<<endl;
	}
	return 0;
}