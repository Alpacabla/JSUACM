// Problem: B. Friends and Candies
// Contest: Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.com/contest/1538/problem/B
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
		vector<int> a(n+1);
		ll sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%n){
			cout<<"-1"<<endl;
		}else{
			int k=sum/n;
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]>k) cnt++;
			}
			cout<<cnt<<endl;
		}
	}
	return 0;
}