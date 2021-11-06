// Problem: A. Linear Keyboard
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		string s1,s2;
		cin>>s1>>s2;
		vector<int> pos(26);
		for(int i=0;i<s1.size();i++){
			pos[s1[i]-'a']=i;
		}
		int ans=0;
		int p=pos[s2[0]-'a'];
		for(int i=1;i<s2.size();i++){
			ans+=abs(pos[s2[i]-'a']-p);
			p=pos[s2[i]-'a'];
		}
		cout<<ans<<endl;
	}
	return 0;
}