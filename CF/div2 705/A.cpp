/*
link: 
tags: 
*/
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
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> ans;
		for(int i=m+1;i<=n;i++){
			ans.push_back(i);
		}
		for(int i=m%2?m/2+1:m/2;i<m;i++){
			ans.push_back(i);
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}