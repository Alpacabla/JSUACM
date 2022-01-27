// Problem: B. Fun with Even Subarrays
// Contest: Codeforces - Codeforces Round #768 (Div. 2)
// URL: https://codeforces.com/contest/1631/problem/B
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
bool check(vector<int> &a){
	for(int i=1;i<a.size();i++){
		if(a[i]!=a[1]) return true;
	}
	return false;
}
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
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		int len=1;
		while(check(a)){
			while(n-len>=1&&a[n-len]==a[n]){
				len++;
			}
			for(int i=max(1,n-2*len+1);i<=n;i++){
				a[i]=a[n];
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}