/*
link: https://loj.ac/problem/2153
tags: 状压dp
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
const int max_n=(1<<5)+10000;
ll dp[10][150][max_n];
int sta[max_n],cnt_1[max_n],tot;
void init(const int lim,const int k)
{
	for(int i=0;i<=lim;i++){
		int t=i;
		int cnt=0;
		if(i&(i<<1)) continue;
		for(int j=0;j<15;j++){
			if((1<<j)&i) cnt++;
		}
		cnt_1[tot]=cnt;
		sta[tot++]=i;
	}
	return ;
}
bool judge(int a,int b){
	if(a&b) return false;
	if(a&(b<<1)) return false;
	if((a<<1)&b) return false;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,o,p;
	int n,k;
	int lim;
	cin>>n>>k;
	lim=(1<<(n))-1;
	tot=0;
	init(lim,k);
	ll ans=0;
	dp[0][0][0]=1;
	for(i=1;i<=n;i++){
		for(j=0;j<=k;j++){
			for(p=0;p<tot;p++){
				for(o=0;o<tot;o++){
					if(judge(sta[o],sta[p])&&j-cnt_1[o]>=0){
							dp[i][j][o]+=dp[i-1][j-cnt_1[o]][p];
					}
				}
			}
		}
	}
	for(j=0;j<tot;j++){
		ans+=dp[n][k][j];
	}
	cout<<ans<<endl;
	return 0;
}
