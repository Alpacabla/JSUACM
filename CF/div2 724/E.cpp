// Problem: E. Omkar and Forest
// Contest: Codeforces - Codeforces Round #724 (Div. 2)
// URL: https://codeforces.com/contest/1536/problem/E
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
const int mod=1e9+7;
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
		}
		int ans=1;
		int cnt=1;
		for(int i=1;i<=n;i++){
			for(int j=0;j<m;j++){
				if(s[i][j]=='#'){
					ans=ans*2%mod;
				}else{
					cnt=0;
				}
			}
		}
		cout<<(ans-cnt+mod)%mod<<endl;
	}
	return 0;
}