// Problem: F. Top-Notch Insertions
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/F
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
bool check(vector<int> &a)
{
	for(int i=1;i<a.size();i++){
		if(a[i]<a[i-1]) return true;
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
		while(check(a)){
			ans++;
			if(ans%2==1){
				for(int i=1;i<=n-2;i+=2){
					if(a[i]>a[i+1]){
						swap(a[i],a[i+1]);
					}
				}
			}else{
				for(int i=2;i<=n-1;i+=2){
					if(a[i]>a[i+1]){
						swap(a[i],a[i+1]);
					}
				}
			}
			// for(int i=1;i<=n;i++){
				// cout<<a[i]<<" ";
			// }
			// cout<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}