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
	int n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		vector<bool>vis(101);
		int ans=0;
		while(n--){
			int a;
			cin>>a;
			vis[a]=true;
		}
		while(m--){
			int a;
			cin>>a;
			if(vis[a]){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}