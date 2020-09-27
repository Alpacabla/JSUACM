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
const int max_n=2300;
const int max_m=1e6+1e5;
int dp[120][max_n],sta1[120],cnt1[120],sta[max_n],cnt[max_n],tot,dd[max_m][2],tot1;
char s[120][15];
int ss[120];
int m;
#define judge(a,b) (!(a&b)&&!(a&(b>>m)))
#define can(a,b) (!(sta[a]&ss[b])&&!((sta[a]>>m)&ss[b-1]))
// inline bool judge(int a,int b)
// {
// 	if(a&b) return false;
// 	if(a&(b>>m)) return false;
// 	return true;
// }
void init(const int n)
{
	const int lim=(1<<m)-1;
	for(int i=0;i<=lim;i++){
		if((i&(i<<1))||(i&(i<<2))) continue;
		sta1[tot]=i;
		int t=i;
		while(t){
			cnt1[tot]+=(t&1);
			t>>=1;
		}
		tot++;
	}
	int len=tot;
	tot=0;
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(!(sta1[i]&sta1[j])){
				sta[tot]=(sta1[i]<<(m))+sta1[j];
				cnt[tot++]=cnt1[i]+cnt1[j];
			}
		}
	}
	tot1=tot;
	len=tot;
	tot=0;
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			if(judge(sta[j],sta[i])){
				dd[tot][0]=i;
				dd[tot++][1]=j;
			}
		}
	}
	ss[1]=ss[0]=lim;
	for(int i=2;i<n+2;i++){
		for(int j=m-1,t=1;j>=0;j--,t<<=1){
			ss[i]+=(s[i][j]=='H')*t;
		}
	}
	return ;
}
// inline bool can(int a,int b)
// {
// 	if(!(sta[a]&ss[b])&&!((sta[a]>>m)&ss[b-1])) return true;
// 	else return false;
// }
int main()
{
	int i,j,k,l;
	int n;
	scanf("%d%d",&n,&m);
	for(i=2;i<n+2;i++){
		scanf("%s",s[i]);
	}
	init(n);
	if(n%2){
		ss[n+2]=(1<<m)-1;
		n++;
	}
	for(i=3;i<n+2;i+=2){
		for(j=0;j<tot;j++){
			if(can(dd[j][0],i)&&can(dd[j][1],i-2)){
				dp[i][dd[j][0]]=max(dp[i][dd[j][0]],dp[i-2][dd[j][1]]+cnt[dd[j][0]]);
			}
		}
	}
	//cout<<min1<<endl;
	//cout<<max2<<endl;
	//cout<<'u'<<endl;
	int ans=-1;
	for(i=0;i<tot1;i++){
		ans=max(ans,dp[n+2-1][i]);
	}
	printf("%d\n",ans);
	return 0;
}
