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
int val[5005][5005];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,r;
	cin>>n>>r;
	for(int i=1;i<=n;i++){
		int x,y,v;
		cin>>x>>y>>v;
		val[x+1][y+1]=v;
	}
	for(int i=1;i<=5001;i++){
		for(int j=1;j<=5001;j++){
			val[i][j]+=val[i-1][j]+val[i][j-1]-val[i-1][j-1];
		}
	}
	int ans=-1;
	for(int i=r;i<=5001;i++){
		for(int j=r;j<=5001;j++){
			ans=max(ans,val[i][j]+val[i-r][j-r]-val[i-r][j]-val[i][j-r]);
		}
	}
	cout<<ans<<endl;
	return 0;
}