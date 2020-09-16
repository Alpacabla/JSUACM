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
int num[105][105];
int sum[105][105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k;
	int n;
	cin>>n;
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cin>>num[i][j];
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			sum[i][j]=sum[i-1][j]+num[i][j];
		}
	}
	int ans=-int_inf;
	for(i=1;i<=n;i++){
		for(j=1;(j+i-1)<=n;j++){
			int t=-int_inf;
			for(k=1;k<=n;k++){
				if(t<0){
					t=0;
				}
				t+=sum[j+i-1][k]-sum[j][k];
				ans=max(ans,t);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
