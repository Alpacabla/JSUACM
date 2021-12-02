// Problem: B. William the Vigilant
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/B
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
	int n,t;
	cin>>n>>t;
	string s;
	cin>>s;
	int cnt=0;
	auto now=-1;
	while((now=s.find("abc",now+1))!=string::npos){
		cnt++;
	}
	auto check=[&s](int pos) -> bool{
		static string ss="abc";
		for(int i=-2;i<=0;i++){
			int tot=0;
			for(int j=pos+i;j<s.size()&&j<pos+i+3;j++){
				if(ss[tot]!=s[j]) break;
				tot++;
			}
			if(tot==3) return true;
		}
		return false;
	};
	while(t--){
		int pos;
		char ch;
		cin>>pos>>ch;
		if(check(pos-1)) cnt--;
		s[pos-1]=ch;
		if(check(pos-1)) cnt++;
		cout<<cnt<<endl;
	}
	
	return 0;
}