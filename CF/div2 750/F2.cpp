// Problem: F2. Korney Korneevich and XOR (hard version)
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/F2
// Memory Limit: 512 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#pragma GCCoptimize(3)
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=8200;
bool ans[max_n];
stack<int> vis[max_n];
stack<int> xorv[max_n];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ans[0]=true;
	for(int i=0;i<max_n;i++){
		for(int j=0;j<max_n;j++){
			vis[i].push(j);
		}
		xorv[i].push(0);
	}
	
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		while(xorv[a].size()){
			int k=xorv[a].top()^a;
			xorv[a].pop();
			ans[k]=true;
			while(vis[k].top()>a){
				int z=vis[k].top();
				vis[k].pop();
				xorv[z].push(k);
			}
		}
	}
	vector<int> out;
	for(int i=0;i<8192;i++){
		if(ans[i]) out.push_back(i);
	}
	cout<<out.size()<<endl;
	for(auto a:out){
		cout<<a<<" ";
	}
	cout<<endl;
	return 0;
}