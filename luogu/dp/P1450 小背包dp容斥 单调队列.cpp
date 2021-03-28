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
ll cnt[5];
vector<ll> dp[5];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a[5];
	int n;
	for(int i=1;i<=4;i++){
		cin>>a[i];
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;
		for(int j=1;j<=4;j++){
			cin>>cnt[j];
		}
		cin>>m;
		for(int i=0;i<=4;i++){
			dp[i].resize(m+1);
			dp[i][0]=1;
		}
		//cout<<dp[0][0]<<endl;
		for(int j=1;j<=4;j++){
			ll max1=-1;
			for(int k=a[j];k<=m;k++){
				//cout<<k<<endl;
				if(k>=(a[j]*(cnt[j]+1))){
					dp[j][k]+=max1;//dp[j-1][k]+dp[j-1][k-a[j]*cnt[j]];//-dp[j-1][k-a[j]*cnt[j]];
				}else{
					max1=max(max1,dp[j][k]+=dp[j][k-a[j]]+dp[j-1][k]);
				}
				cout<<dp[j][k]<<" ";
			}
			cout<<endl;
		}
		cout<<dp[4][m]<<endl;
	}
	return 0;
}