// Problem: A. Divide and Multiply
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/A
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
		int n;
		cin>>n;
		vector<int> a(n+1);
		ll ans=0,xx=1;
		int max1=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			while(a[i]%2==0){
				a[i]/=2;
				xx<<=1;
			}
			if(max1<a[i]) max1=a[i]; 
		}
		for(int i=1;i<=n;i++){
			if(max1==a[i]){
				ans+=max1*xx;
				max1=-1;
			}else{
				ans+=a[i];
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}