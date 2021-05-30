// Problem: C. Compression and Expansion
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/C
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
const int max_n=1e4+5;
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
		for(int i=1;i<=n;i++) cin>>a[i];
		vector<int> ans(n+1);
		int ind=0;
		//ans[0]=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1){
				ans[ind++]=1;
			}else{
				while(ans[ind-1]!=a[i]-1){
					ind--;
				}
				ans[ind-1]=a[i];
			}
			for(int j=0;j<ind;j++){
				cout<<ans[j]<<(j==ind-1?"":".");
			}
			cout<<endl;
		}
	}
	return 0;
}