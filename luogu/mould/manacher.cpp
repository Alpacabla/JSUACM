#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int max_n=2.2e7+20;
int dp[max_n];
char s[max_n];
char t_s[max_n];
int pre(int len)
{
	int i;
	int cnt=0;
	s[cnt++]='~';
	for(i=0;i<len;i++){
		s[cnt++]='#';
		s[cnt++]=t_s[i];
	}
	s[cnt++]='#';
	s[cnt++]='^';
	return cnt;
}
void manacher(int len)
{
	int i;
	int r=0,c=0,t;
	len-=1;
	for(i=1;i<len;i++){
		t=c+c-i;
		if(r>i){
			dp[i]=min(dp[t],r-i);
		}else{
			dp[i]=0;
		}
		while(s[i-1-dp[i]]==s[i+1+dp[i]]){
			dp[i]++;
		}
		if(i+dp[i]>r){
			c=i;
			r=i+dp[i];
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t_s;
	int len=strlen(t_s);
	manacher(len=pre(len));
	int ans=1,i;
	for(i=0;i<len;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}