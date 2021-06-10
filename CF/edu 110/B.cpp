// Problem: B. Array Reodering
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/B
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a,b;
		for(int i=1;i<=n;i++){
			int t;
			cin>>t;
			if(t%2){
				b.push_back(t);
			}else a.push_back(t);
		}
		for(int i=0;i<b.size();i++){
			a.push_back(b[i]);
		}
		int cnt=0;
		for(int i=0;i<a.size();i++){
			for(int j=i+1;j<a.size();j++){
				if(__gcd(a[i],a[j]*2)>1) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}