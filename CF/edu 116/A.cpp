// Problem: A. AB Balance
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/A
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
bool check(string &s)
{
	int cnt1=0;
	for(int i=1;i<s.size();i++){
		if(s[i]=='a'&&s[i-1]=='b') cnt1++;
		if(s[i]=='b'&&s[i-1]=='a') cnt1--;
	}
	return cnt1==0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int now=0;
		if(check(s)){
			cout<<s<<endl;
			continue;
		}
		while(now<s.size()){
			char ch=s[now];
			s[now]=(ch=='a')?'b':'a';
			if(check(s)){
				break;
			}
			s[now++]=ch;
		}
		cout<<s<<endl;
	}
	return 0;
}