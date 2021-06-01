// Problem: B - Uniformly Distributed
// Contest: AtCoder - AtCoder Regular Contest 120
// URL: https://atcoder.jp/contests/arc120/tasks/arc120_b?lang=en
// Memory Limit: 1024 MB
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
const ll mod=998244353;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<string> a(n+1);
	vector<int> cnt[3];
	for(int i=0;i<3;i++) cnt[i].resize(n+m);
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=0;j<m;j++) cnt[((string)"BR.").find(a[i][j])][i+j]++;
	}
	ll ans=1;
	for(int i=0;i<=n+m-2;i++){
		if(cnt[0][i]*cnt[1][i]){
			ans=0;
			break;
		}
		if(cnt[0][i]==0&&cnt[1][i]==0){
			ans=ans*2%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}