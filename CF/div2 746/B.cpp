// Problem: B. Hemose Shopping
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/B
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
		int n,k;
		cin>>n>>k;
		vector<int> a(n+1),b;
		for(int i=1;i<=n;i++) cin>>a[i];
		b=a;
		sort(b.begin()+1,b.end());
		if(n>=2*k){
			cout<<"YES"<<endl;
			continue;
		}
		bool flag=true;
		for(int i=n-k+1;i<=k;i++){
			if(b[i]!=a[i]) flag=false;
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}