// Problem: A. Divan and a Store
// Contest: Codeforces - Codeforces Round #757 (Div. 2)
// URL: https://codeforces.com/contest/1614/problem/A
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
		int n,l,r,k;
		cin>>n>>l>>r>>k;
		vector<int> a;
		for(int i=1;i<=n;i++){
			int v;
			cin>>v;
			if(v<=r&&v>=l) a.push_back(v);
		}
		sort(a.begin(),a.end());
		int cnt=0;
		for(int i=0;i<a.size();i++){
			if(k>=a[i]){
				k-=a[i];
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}