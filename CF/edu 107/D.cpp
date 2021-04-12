// Problem: D. Min Cost String
// Contest: Codeforces - Educational Codeforces Round 107 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1511/problem/D
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
bool vis[150][150];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	string s="";
	char last=0;
	int len=0;
	for(char ch='a';ch<'a'+m&&len<n;ch++){
		s+=ch;
		len++;
		for(char k=ch+1;k<'a'+m&&len<n;k++){
			string add="";
			add+=ch;
			add+=k;
			if(len+1==n){
				s+=k;
				len++;
			}else{
				s+=add;
				len+=2;
			}
		}
		if(len==n) break;
	}
	for(int j=s.size(),k=0;j<n;j++){
		s+=s[k++];
	}
	cout<<s<<endl;
	return 0;
}