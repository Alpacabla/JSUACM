// Problem: B. Plus and Multiply
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/B
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		ll n,a,b;
		cin>>n>>a>>b;
		bool flag=false;
		if(a!=1){
			ll now=1;
			while(now<=n){
				ll x=now;
				if((n-x)%b==0){
					flag=true;
					break;
				}
				now=now*a;
			}
		}else{
			flag=(n-1)%b==0?true:false;
		}
		cout<<(flag?"Yes":"No")<<endl;
	}
	return 0;
}