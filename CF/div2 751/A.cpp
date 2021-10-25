// Problem: A. Two Subsequences
// Contest: Codeforces - Codeforces Round #751 (Div. 2)
// URL: https://codeforces.com/contest/1602/problem/A
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
		string s;
		cin>>s;
		char ch='z';
		for(int i=0;i<s.size();i++){
			ch=min(ch,s[i]);
		}
		bool flag=false;
		string t="";
		for(int i=0;i<s.size();i++){
			if(!flag&&s[i]==ch){
				flag=true;
			}else{
				t+=s[i];
			}
		}
		cout<<ch<<" "<<t<<endl;
	}
	return 0;
}