// Problem: B. Box Fitting
// Contest: Codeforces - CodeCraft-21 and Codeforces Round #711 (Div. 2)
// URL: https://codeforces.com/contest/1498/problem/B
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
	int t;
	cin>>t;
	while(t--){
		int n,w;
		cin>>n>>w;
		multiset<int> s;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			s.insert(a);
		}
		int ans=0;
		while(s.size()){
			ans++;
			int sum=w;
			while(s.size()){
				auto it=s.upper_bound(sum);
				if(it!=s.begin()){
					it=prev(it);
					sum-=*it;
					s.erase(it);
				}else{
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}