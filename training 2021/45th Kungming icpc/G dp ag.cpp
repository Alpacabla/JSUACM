/*
link: https://ac.nowcoder.com/acm/contest/12548/G
tags: 很好的类背包的 dp
	  首先对于生日的时间要从小到大排序，不然大的生日不一定能得到最大的转移
	  二是这里 dp[i][j][k] 的含义是指前 i 个生日里用 j 天的时间并且剩 k
	  个人的生日不理选礼物的最大值，接着再用这个 dp 值加对选择 k 个礼物可以
	  得到的最大价值，这个值可以用 dp 预处理或者直接 (1<<m) 次的枚举 (m<=15)
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
int dp[366][16];
char s[12];
struct node{
	int T;
	int c,v;
	bool operator < (const node a) const {
		return  T<a.T;
	}
}birth[505];
int a[16],b[16];
int MAX[16];
int mon[13]={
	0,31,28,31,30,31,30,31,31,30,31,30,31
};
int sum[13];
int main()
{
	int t;
	for(int i=1;i<=12;i++){
		sum[i]=sum[i-1]+mon[i];
	}
	scanf("%d",&t);
	while(t--){
		int n,m,w;
		scanf("%d%d%d",&n,&m,&w);
		int now=1;
		for(int i=1;i<=n;i++){
			scanf("%s%d%d",s,&(birth[now].c),&(birth[now].v));
			birth[now].T=sum[(s[5]-'0')*10+(s[6]-'0')-1]+(s[8]-'0')*10+(s[9]-'0');
			if((birth[now].T==60&&s[6]=='2')){
				//now--;
			}else{
				now++;
			}
		}
		for(int i=1;i<=m;i++){
			scanf("%d%d",a+i,b+i);
		}
		sort(birth+1,birth+now);
		memset(dp,-0x3f,sizeof(dp));
		memset(MAX,0,sizeof(MAX));
		MAX[0]=0;
		for(int i=0;(i<(1<<m));i++){
			int cnt=0;
			int ww=0;
			int res=0;
			for(int j=0;j<m;j++){
				if((i>>j)&1){
					cnt++;
					ww+=a[j+1];
					res+=b[j+1];
				}
			}
			if(ww<=w){
				MAX[cnt]=max(MAX[cnt],res);
			}
		}
		int ans=0;
        dp[0][0]=0;
		for(int i=1;i<now;i++){
            for(int j=birth[i].T;j>=0;j--){
				//int temp=dp[j][0];
				for(int k=min(i,m);k>=0;k--){
					if(j>=birth[i].c&&birth[i].T>=birth[i].c) dp[j][k]=max(dp[j][k],dp[j-birth[i].c][k]+birth[i].v);
					dp[j][k]=max(dp[j][k],dp[j][0]+MAX[k]);
					ans=max(ans,dp[j][k]);
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}