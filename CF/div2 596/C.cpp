// Problem: C. p-binary
// Contest: Codeforces - Codeforces Round #596 (Div. 2, based on Technocup 2020 Elimination Round 2)
// URL: https://codeforces.com/contest/1247/problem/C
// Memory Limit: 512 MB
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
	int n,p;
	cin>>n>>p;
	int ans=-1;
	for(int i=1;i<=2e6;i++){
		int z=n-p*i;
		if(z<=0){
			continue;
		}
		if(z>=i&&i>=__builtin_popcount(z)){
			ans=i;
			break;
		}
	}
	cout<<ans<<endl;
	return 0;
}