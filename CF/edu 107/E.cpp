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
const int max_n=3e5+5;
const int mod=998244353;
ll dp[max_n][2],val[max_n];
ll pow2[max_n];
inline void init(const int n)
{
	pow2[0]=1;
	for(int i=1;i<=n;i++){
		pow2[i]=pow2[i-1]*2%mod;
	}
	for(int i=2;i<=n;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%mod;
		dp[i][1]=((2*((dp[i-2][0]+dp[i-2][1])%mod))%mod+pow2[i-2])%mod;
		val[i]=(dp[i][0]+dp[i][1])%mod;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(3e5);
	int n,m;
	cin>>n>>m;
	vector<vector<char> >a(n+1);
	int cnt=0;
	for(int i=1;i<=n;i++){
		a[i].resize(m+1);
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
			if(a[i][j]=='o') cnt++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='o'){
				int len=0;
				while(j<=m&&a[i][j]=='o'){
					j++;
					len++;
				}
				ans=(ans+(pow2[cnt-len]*val[len])%mod)%mod;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a[j][i]=='o'){
				int len=0;
				while(j<=n&&a[j][i]=='o'){
					j++;
					len++;
				}
				ans=(ans+(pow2[cnt-len]*val[len])%mod)%mod;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}