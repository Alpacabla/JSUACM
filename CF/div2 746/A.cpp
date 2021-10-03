// Problem: A. Gamer Hemose
// Contest: Codeforces - Codeforces Round #746 (Div. 2)
// URL: https://codeforces.com/contest/1592/problem/0
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
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n==1){
			n++;
			a.push_back(a[1]);
		}
		sort(a.begin()+1,a.end());
		int ans=0;
		if(m<=a[n]){
			ans=1;
		}else{
			if(m<=a[n]+a[n-1]){
				ans=2;
			}else{
				ll sum=a[n]+a[n-1];
				ll k=m/sum;
				ans=k*2;
				m-=k*sum;
				if(m>0){
					if(m>a[n]) ans++;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}