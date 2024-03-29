// Problem: E. Mocha and Stars
// Contest: Codeforces - Codeforces Round #738 (Div. 2)
// URL: https://codeforces.com/contest/1559/problem/E
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
		vector<bool> flag(31,true);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			for(int j=0;j<31;j++){
				if((a[i]&(1<<j))==0){
					flag[j]=0;
				}
			}
		}
		int ans=0;
		for(int i=0;i<31;i++){
			if(flag[i]) ans+=(1<<i);
		}
		cout<<ans<<endl;
	}
	return 0;
}