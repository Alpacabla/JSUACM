// Problem: D1. Two Hundred Twenty One (easy version)
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// URL: https://codeforces.com/contest/1562/problem/D1
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
		int n,q;
		cin>>n>>q;
		string s;
		vector<int> a(n+1);
		vector<int> sum1(n+1),sum2(n+1);
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='-') a[i+1]=-1;
			else a[i+1]=1;
		}
		for(int i=1;i<=n;i++){
			if(i%2){
				sum1[i]=a[i]+sum1[i-1];
				sum2[i]=-a[i]+sum2[i-1];
			}else{
				sum1[i]=-a[i]+sum1[i-1];
				sum2[i]=a[i]+sum2[i-1];
			}
		}
		while(q--){
			int a,b;
			int ans=0;
			cin>>a>>b;
			if(a%2){
				int d=sum1[b]-sum1[a-1];
				if(d){
					if(d%2){
						ans=1;
					}else{
						ans=2;
					}
				}else{
					ans=0;
				}
			}else{
				int d=sum2[b]-sum2[a-1];
				if(d){
					if(d%2){
						ans=1;
					}else{
						ans=2;
					}
				}else{
					ans=0;
				}
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}