// Problem: C. Save More Mice
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/C
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
		int n,k;
		cin>>n>>k;
		vector<int> a(k+1);
		for(int i=1;i<=k;i++){
			cin>>a[i];
		}
		int ans=0;
		sort(a.begin()+1,a.end());
		ll now=0;
		int l=1,r=k;
		while(1){
			ans++;
			now+=(n-a[r]);
			r--;
			while(l<=k&&a[l]<=now){
				l++;
			}
			if(l>r){
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}