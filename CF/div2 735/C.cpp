// Problem: C. Mikasa
// Contest: Codeforces - Codeforces Round #735 (Div. 2)
// URL: https://codeforces.com/contest/1554/problem/C
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
		ll a,b;
		cin>>a>>b;
		if(a>b) cout<<0<<endl;
		else{
			int ans=0;
			b++;
			for(int i=30;i>=0;i--){
				int v1=(a>>i)&1,v2=(b>>i)&1;
				if(v1==v2) continue;
				if(v1<v2) ans+=(1<<i);
				else break;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}