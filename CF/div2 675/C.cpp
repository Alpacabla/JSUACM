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
ll dp[max_n];
const ll mod=1e9+7;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	if(s.size()==1){
		cout<<0<<endl;
	}else{
		dp[0]=0;
		ll sum,now,x,times;
		now=s[0]-'0'+(s[1]-'0')*10;
		sum=now+s[0]-'0';
		x=100;
		times=20;
		dp[1]=s[0]-'0'+s[1]-'0';
		for(i=2;i<=s.size();i++){
			dp[i]=(dp[i-1]+s[i]-'0'+sum)%mod;
			dp[i]=(dp[i]+1ll*(s[i]-'0')*times)%mod;
			now=(now+(s[i]-'0')*x)%mod;
			sum=(sum+now)%mod;
			times=(times+(i+1)*x)%mod;
			x=(x*10)%mod;
		}
		cout<<dp[s.size()-1]<<endl;
	}
	return 0;
}
