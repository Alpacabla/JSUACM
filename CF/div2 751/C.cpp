// Problem: C. Array Elimination
// Contest: Codeforces - Codeforces Round #751 (Div. 2)
// URL: https://codeforces.com/contest/1602/problem/C
// Memory Limit: 512 MB
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
		int n;
		cin>>n;
		vector<int> a(n+1);
		vector<int> vis(32);
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]!=0){
				flag=false;
			}
			for(int j=0;j<=30;j++){
				vis[j]+=(a[i]>>j)&1;
			}
		}
		if(flag){
			for(int i=1;i<=n;i++) cout<<i<<" ";
			cout<<endl;
		}else{
			int g=0;
			for(int i=0;i<=30;i++){
				g=__gcd(g,vis[i]);
			}
			for(int i=1;i<=g;i++){
				if(g%i==0){
					cout<<i<<" ";
				}
			}
			cout<<endl;
		}
		
	}
	return 0;
}