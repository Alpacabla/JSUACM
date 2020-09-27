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
const int max_n=105;
int dp[105][max_n],sta[max_n],cnt[max_n],tot,last[105][max_n][max_n],lastcnt[105][max_n];
char s[105][15];
int ss[105];
inline void init(const int n,const int m)
{
	const int lim=(1<<m)-1;
	for(int i=0;i<=lim;i++){
		if((i&(i<<1))||(i&(i<<2))) continue;
		sta[tot]=i;
		int t=i;
		while(t){
			cnt[tot]+=(t&1);
			t>>=1;
		}
		tot++;
	}
	for(int i=2;i<n+2;i++){
		for(int j=m-1,t=1;j>=0;j--,t<<=1){
			ss[i]+=(s[i][j]=='H')*t;
		}
	}
	return ;
}
int main()
{
	int i,j,k,l;
	int n,m;
	scanf("%d%d",&n,&m);
	for(i=2;i<n+2;i++){
		scanf("%s",s[i]);
	}
	init(n,m);
	for(i=2;i<n+2;i++){
		//cout<<"i: "<<i<<endl;
		for(j=0;j<tot;j++){
			if(!(sta[j]&ss[i])){
				for(k=0;k<tot;k++){
					if(!(sta[k]&ss[i-1])&&!(sta[j]&sta[k])){
						if(dp[i][j]<=dp[i-1][k]+cnt[j]){
							int max1=-1;
							for(l=0;l<=lastcnt[i-1][k];l++){
								if(!(sta[j]&sta[last[i-1][k][l]])){
									max1=dp[i-1][k]+cnt[j];
									// cout<<"max1 "<<max1<<endl;
									// cout<<sta[last[i-1][k][l]]<<endl;
									// cout<<sta[k]<<endl;
									// cout<<sta[j]<<endl;
									break;
								}
							}
							if(max1>=dp[i][j]){
								if(max1>dp[i][j]){
									dp[i][j]=max1;
									lastcnt[i][j]=0;
									last[i][j][0]=k;
								}else{
									//cout<<"no"<<endl;
									last[i][j][++lastcnt[i][j]]=k;
								}
							}
						}
					}
				}
			}
		}
	}
	int ans=-1;
	for(i=0;i<tot;i++){
		ans=max(ans,dp[n+2-1][i]);
	}
	cout<<ans<<endl;
	return 0;
}
