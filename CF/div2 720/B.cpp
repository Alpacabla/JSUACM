// Problem: B. Nastia and a Good Array
// Contest: Codeforces - Codeforces Round #720 (Div. 2)
// URL: https://codeforces.com/contest/1521/problem/B
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int k=min_element(a.begin()+1,a.end())-a.begin();
		int cnt=n;
		if(k==1){
			cnt-=1;
		}
		cout<<cnt<<endl;
		if(k!=1){
			cout<<1<<" "<<k<<" "<<a[k]<<" "<<a[k]+1<<endl;
		}
		for(int i=2;i<=n;i++){
			cout<<1<<" "<<i<<" "<<a[k]<<" "<<a[k]+i-1<<endl;
		}
	}
	return 0;
}