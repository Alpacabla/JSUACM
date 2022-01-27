// Problem: D. Not Adding
// Contest: Codeforces - Codeforces Round #766 (Div. 2)
// URL: https://codeforces.com/contest/1627/problem/D
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
	int n;
	cin>>n;
	vector<int> vis((int)1e6+1);
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		vis[a]=a;
	}
	int ans=0;
	for(int i=1;i<=1e6;i++){
		for(int j=2*i;j<=1e6;j+=i){
			vis[i]=__gcd(vis[i],vis[j]);
		}
		if(vis[i]==i) ans++;
	}
	cout<<ans-n<<endl;
	return 0;
}