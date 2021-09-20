// Problem: B. Swaps
// Contest: Codeforces - Codeforces Round #743 (Div. 2)
// URL: https://codeforces.com/contest/1573/problem/B
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
		vector<int> a(n+1),b(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) cin>>b[i];
		vector<int> min1(n+1),max1(n+1);
		//min1[0]=int_inf;
		//for(int i=1;i<=n;i++) min1[i]=min(min1[i-1],a[i]);
		for(int i=1;i<=n;i++) max1[i]=max(max1[i-1],b[i]);
		int ans=int_inf;
		for(int i=1;i<=n;i++){
			ans=min(ans,(int)(lower_bound(max1.begin()+1,max1.end(),a[i])-max1.begin())-1+i-1);
		}
		cout<<ans<<endl;
	}
	return 0;
}