// Problem: A. Sasha and a Bit of Relax
// Contest: Codeforces - Codeforces Round #539 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1109/A
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
	int n;
	cin>>n;
	vector<int> a(n+1);
	vector<int> sum(n+2);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		sum[i]=sum[i+1]^a[i];
	}
	ll ans=0;
	vector<int> cnt[2];
	cnt[0].resize(1<<20);
	cnt[1].resize(1<<20);
	for(int i=1;i<=n;i++){
		int k=sum[i];
		ans+=cnt[!(i%2)][a[i]^k];
		cnt[i%2][sum[i]]++;
	}
	cout<<ans<<endl;
	return 0;
}