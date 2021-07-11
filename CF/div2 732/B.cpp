// Problem: B. AquaMoon and Stolen String
// Contest: Codeforces - Codeforces Round #732 (Div. 2)
// URL: https://codeforces.com/contest/1546/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		int n,m;
		cin>>n>>m;
		vector<string> s(n+1);
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		vector<string> ss(n);
		for(int i=1;i<n;i++){
			cin>>ss[i];
		}
		vector<bool> vis(n+1,true);
		for(int i=0;i<m;i++){
			vector<int> cnt1(26),cnt2(26);
			for(int j=1;j<=n;j++){
				cnt1[s[j][i]-'a']++;
			}
			for(int j=1;j<n;j++){
				cnt2[ss[j][i]-'a']++;
			}
			for(int j=1;j<=n;j++){
				if(vis[j]){
					if(cnt1[s[j][i]-'a']-1!=cnt2[s[j][i]-'a']){
						vis[j]=false;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]){
				cout<<s[i]<<endl;
				cout.flush();
				break;
			}
		}
	}
	return 0;
}