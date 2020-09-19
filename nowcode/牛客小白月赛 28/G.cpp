/*
link: 
tags: 
*/
#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+5;
char s[max_n];
char b[max_n];
int z[max_n];
int dp[max_n];
int len1;
int get_res()
{
	register int len2=strlen(b),max1=-1;
	memset(dp,0,sizeof(int)*len2);
	for(register int i=0,r=0,l=0;i<len2;i++){
		if(i<=r) dp[i]=min(z[i-l],r-i);
		while(i+dp[i]<len2&&s[dp[i]]==b[i+dp[i]]) ++dp[i];
		if(i+dp[i]-1>r)	l=i,r=i+dp[i]-1;
		max1=max(max1,dp[i]);
	}
	return max1;
}
void get_kmp()
{
	int i,r,l;
	l=0,r=0;
	for(i=1;i<len1;i++){
		if(i<=r) z[i]=min(z[i-l],r-i);
		while(i+z[i]<len1&&s[z[i]]==s[i+z[i]]) ++z[i];
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
	return ;
}
int main()
{
	int i,j;
	int n;
	scanf("%s",s);
	len1=strlen(s);
	get_kmp();
	scanf("%d",&n);
	int ans=0;
	for(i=0;i<n;i++){
		scanf("%s",b);
		ans+=get_res();
	}
	printf("%d\n",ans);
	return 0;
}
