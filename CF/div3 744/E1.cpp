// Problem: E1. Permutation Minimization by Deque
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/E1
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
		deque<int> dq;
		
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			if(dq.empty()) dq.push_back(a);
			else{
				if(a<dq.front()) dq.push_front(a);
				else dq.push_back(a);
			}
		}
		for(auto v:dq){
			cout<<v<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}