// Problem: B. Coloring Rectangles
// Contest: Codeforces - Codeforces Round #755 (Div. 2, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.com/contest/1589/problem/B
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
		int a,b;
		cin>>a>>b;
		if(a<b) swap(a,b);
		int ans=0;
		ans+=a/3*b;
		a%=3;
		ans+=b/3*a;
		b%=3;
		if(a*b==1||a*b==2) ans++;
		if(a*b==4) ans+=2;
		cout<<ans<<endl; 
	}
	
	
	return 0;
}