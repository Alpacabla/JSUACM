// Problem: C. Stable Groups
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.com/contest/1539/problem/C
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
	ll m,x;
	cin>>n>>m>>x;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end());
	int cnt=1;
	ll sum=0;
	vector<ll> d;
	
	a[0]=a[1];
	for(int i=1;i<=n;i++){
		while(i<=n&&a[i]-a[i-1]<=x){
			i++;
		}
		if(i>n) break;
		cnt++;
		d.push_back((a[i]-a[i-1]+x-1)/x-1);
	}
	
	sort(d.begin(),d.end());
	
	for(int i=0;i<d.size();i++){
		if(m>=d[i]){
			m-=d[i];
			cnt--;
		}else{
			break;
		}
	}
	cout<<cnt<<endl;
	return 0;
}