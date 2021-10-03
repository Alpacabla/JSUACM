// Problem: C. Portal
// Contest: Codeforces - Codeforces Round #745 (Div. 2)
// URL: https://codeforces.com/contest/1581/problem/C
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
		int n,m;
		cin>>n>>m;
		vector<string> s(n+1);
		
		for(int i=1;i<=n;i++){
			cin>>s[i];
			s[i]=' '+s[i];
		}
		vector<vector<int> >sum(n+1,m+1);
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='1');
			}
		}
		int ans=int_inf;
		for(int i=1;i<=n-5+1;i++){
			for(int j=1;j<=m-4+1;j++){
				for(int a1=i+5-1;a1<=n;a1++){
					for(int b1=j+4-1;b1<=m;b1++){
						
					}
				}
			}
		}
	}
	return 0;
}