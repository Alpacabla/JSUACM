// Problem: D. Co-growing Sequence
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/D
// Memory Limit: 512 MB
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
		vector<ll> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		vector<ll> ans(n+1);
		for(int i=0;i<=30;i++){
			ll now=0;
			for(int j=1;j<=n;j++){
				if(now==1){
					if(((a[j]>>i)&1)==0) ans[j]+=(1<<i);
				}else{
					if(((a[j]>>i)&1)==1) now=1;
				}
			}
		}
		for(int i=1;i<ans.size();i++) cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}