// Problem: C. Diluc and Kaeya
// Contest: Codeforces - Codeforces Round #724 (Div. 2)
// URL: https://codeforces.com/contest/1536/problem/C
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
#define endl '\n'
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	string ss="DK";
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		s=" "+s;
		vector<int> ans(n+1);
		map<pair<int,int>,int >mp;
		int cnt[2]={0};
		for(int i=1;i<=n;i++){
			for(int j=0;j<2;j++){
				cnt[j]+=(s[i]==ss[j]);
			}
			int k=__gcd(cnt[0],cnt[1]);
			ans[i]=++mp[make_pair(cnt[0]/k,cnt[1]/k)];
		}
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<(i==n?"":" ");
		}
		cout<<endl;
	}
	return 0;
}