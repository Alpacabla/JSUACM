// Problem: B. Love Song
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.com/contest/1539/problem/B
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
vector<int> sum[26];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<26;i++){
		sum[i].resize(s.size()+1);
	}
	for(int i=0;i<s.size();i++){
		for(int j=0;j<26;j++){
			sum[j][i+1]=sum[j][i]+(s[i]==('a'+j));
		}
	}
	while(m--){
		int a,b;
		cin>>a>>b;
		ll ans=b-a+1;
		for(int i=1;i<26;i++){
			int k=sum[i][b]-sum[i][a-1];
			ans+=1ll*(i)*k;
		}
		cout<<ans<<endl;
	}
	return 0;
}