/*
link: https://www.luogu.com.cn/problem/P1879
tags: 模板状压
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
const int max_n=(1<<13);
const int mod=1e8;
int dp[15][max_n],sta[max_n],tot;
int book[15];
#define bad(a) ((a)&((a)<<1))
#define can(a,b) (!((a)&(b)))
void init(const int n,const int m)
{
	for(int i=1;i<=n;i++){
		int a=0;
		for(int j=0;j<m;j++){
			int b;
			cin>>b;
			a+=(!b)*(1<<j);
		}
		book[i]=a;
	}
	const int lim=(1<<m)-1;
	book[0]=lim;
	for(int i=0;i<=lim;i++){
		if(bad(i)) continue;
		sta[tot++]=i;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k;
	int n,m;
	cin>>n>>m;
	init(n,m);
	dp[0][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<tot;j++){
			if(can(sta[j],book[i])){
				for(k=0;k<tot;k++){
					if(can(sta[k],book[i-1])&&can(sta[j],sta[k])){
						dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
					}
				}
			}
		}
	}
	int ans=0;
	for(i=0;i<tot;i++){
		ans=(ans+dp[n][i])%mod;
	}
	cout<<ans<<endl;
	return 0;
}
