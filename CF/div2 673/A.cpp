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
int num[max_n];
int vis[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	int a,b;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		//int min1=int_inf;
		for(i=0;i<n;i++){
			cin>>num[i];
			//min1=min(min1,num[i]);
		}
		sort(num,num+n);
		int ans=0;
		for(i=1;i<n;i++){
			ans+=(m-num[i])/num[0];
		}
		cout<<ans<<endl;
	}
	return 0;
}
