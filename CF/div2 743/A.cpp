// Problem: A. Countdown
// Contest: Codeforces - Codeforces Round #743 (Div. 2)
// URL: https://codeforces.com/contest/1573/problem/A
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
		string s;
		int n;
		cin>>n;
		cin>>s;
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=s[i]-'0';
			if(i!=n-1&&s[i]-'0') ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}