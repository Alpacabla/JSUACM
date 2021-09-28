// Problem: D. Productive Meeting
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
//#define endl '\n'
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
		vector<pair<int,int> >ans;
		priority_queue<pair<int,int> > q;
		for(int i=1;i<=n;i++){
			if(a[i]) q.push({a[i],i});
		}
		while(q.size()>1){
			pair<int,int> a1,a2;
			a1=q.top();
			q.pop();
			a2=q.top();
			q.pop();
			ans.push_back({a1.second,a2.second});
			a1.first--;
			a2.first--;
			if(a1.first) q.push(a1);
			if(a2.first) q.push(a2);
		}
		cout<<ans.size()<<endl;
		for(auto [a,b]:ans){
			cout<<a<<" "<<b<<endl;
		}
	}
	return 0;
}