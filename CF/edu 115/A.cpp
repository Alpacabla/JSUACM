// Problem: A. Computer Game
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/A
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
	int  t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s1,s2;
		cin>>s1>>s2;
		bool flag=true;
		for(int i=0;i<n;i++){
			if(s1[i]==s2[i]&&s1[i]=='1'){
				flag=false;
				break;
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}