// Problem: E2. Array Optimization by Deque
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/E2
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
const int max_n=2e5+5;
int bit[max_n];
int n;
void add(int a){
	while(a<=n){
		bit[a]++;
		a+=lowbit(a);
	}
}
int qu(int a){
	int res=0;
	while(a){
		res+=bit[a];
		a-=lowbit(a);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> a(n+1),b(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
			bit[i]=0;
		}
		sort(b.begin()+1,b.end());
		int k=unique(b.begin()+1,b.end())-b.begin();
		ll ans=0;
		for(int i=1;i<=n;i++){
			int ind=(int)(lower_bound(b.begin()+1,b.begin()+k,a[i])-b.begin());
			int q=qu(ind-1);
			int d=qu(ind)-q;
			int dd=i-1-d;
			ans+=min(q,dd-q);
			add(ind);
		}
		cout<<ans<<endl;
		
	}
	return 0;
}