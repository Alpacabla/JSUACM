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
	int n;
	cin>>n;
	vector<int> vis(1005);
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		vis[a]++;
	}
	int t;
	cin>>t;
	vector<int> sum(1005);
	for(int i=1;i<=1000;i++){
		sum[i]=sum[i-1]+vis[i];
	}
	int ans=sum[t];
	for(int i=t+1;i<=1000;i++){
		ans=max(ans,sum[i]-sum[i-t-1]);
	}
	cout<<ans<<endl;
	return 0;
}