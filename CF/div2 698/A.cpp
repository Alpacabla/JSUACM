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
int vis[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		int n;
		cin>>n;
		int ans=-1;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			vis[a]++;
			ans=max(ans,vis[a]);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}