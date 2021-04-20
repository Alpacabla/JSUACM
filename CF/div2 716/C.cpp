// Problem: C. Product 1 Modulo N
// Contest: Codeforces - Codeforces Round #716 (Div. 2)
// URL: https://codeforces.com/contest/1514/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
bool pri(int n)
{
	int sqn=sqrt(n);
	for(int i=2;i<=sqn;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	if(pri(n)){
		ll x=1;
		if(n==2){
			cout<<1<<endl;
			cout<<1<<endl;
			return 0;
		}
		cout<<n-2<<endl;
		for(int i=1;i<=n-2;i++){
			cout<<i<<" ";
			x=x*i;
			x%=n;
		}
		cout<<endl;
		return 0;
	}
	vector<int> ans;
	ll x=1;
	int last=1;
	ans.push_back(1);
	for(int i=2;i<=n;i++){
		if(__gcd(i,n)==1){
			ans.push_back(i);
			//last=x;
			x=x*i;
			x%=n;
			if(x==1){
				last=ans.size();
				//break;
			}
		}
	}
	// if(x!=1){
		// ans.pop_back();
	// }
	// cout<<last<<endl;
	// cout<<x<<endl;
	cout<<last<<endl;
	for(int i=0;i<last;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}