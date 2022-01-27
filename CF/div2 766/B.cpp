// Problem: B. Not Sitting
// Contest: Codeforces - Codeforces Round #766 (Div. 2)
// URL: https://codeforces.com/contest/1627/problem/B
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
inline int dis(int x,int y,int xx,int yy){
	return abs(x-xx)+abs(y-yy);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> a;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int d=0;
				d=max(d,dis(i,j,1,1));
				d=max(d,dis(i,j,1,m));
				d=max(d,dis(i,j,n,1));
				d=max(d,dis(i,j,n,m));
				a.push_back(d);
			}
		}
		sort(a.begin(),a.end());
		for(auto v:a){
			cout<<v<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}