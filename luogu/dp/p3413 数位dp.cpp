/*
link: 
tags: 取不能构成回文串的就比较好写了
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
const int max_n=1e3+5;
#define ZERO -1
const int mod=1e9+7;
int dp[max_n][15][15];
ll digdp(vector<int> &a,int now,int pre,int prepre,bool flag)
{
	if(now<0) return pre!=prepre;
	if(pre!=ZERO&&prepre!=ZERO&&!flag&&dp[now][pre][prepre]!=-1) 
		return dp[now][pre][prepre];
	int lim=flag?a[now]:9;
	int res=0;
	for(int i=0;i<=lim;i++){
		if(i==pre||i==prepre) continue;
		res+=digdp(a,now-1,i==0&&pre==ZERO?ZERO:i,pre,flag&&i==lim);
		res%=mod;
	}
	return pre!=ZERO&&prepre!=ZERO&&!flag?dp[now][pre][prepre]=res:res;
}
ll solve(string a,string b)
{
	memset(dp,-1,sizeof(dp));
	vector<int> aa(a.size()),bb(b.size());
	for(int i=0;i<a.size();i++){
		aa[i]=a[i]-'0';
	}
	for(int i=0;i<b.size();i++){
		bb[i]=b[i]-'0';
	}

	ll sum=0;
	for(auto ch:b){
		sum=sum*10+(ch-'0');
		sum%=mod;
	}
	sum=(sum+1)%mod;

	ll del=0;
	for(auto ch:a){
		del=del*10+(ch-'0');
		del%=mod;
	}
	del=(del+1)%mod;
	sum=(sum-del+mod)%mod;
	reverse(aa.begin(),aa.end());
	reverse(bb.begin(),bb.end());

	int out1=digdp(aa,aa.size()-1,ZERO,ZERO,true);
	int out2=digdp(bb,bb.size()-1,ZERO,ZERO,true);
	out1=(out2-out1+mod)%mod;
	auto f=[](string s) -> bool{
		if(s.size()<2) return false;
		if(s.size()==2) return s[0]==s[1];
		bool flag=false;
		for(int i=0;!flag&&i<s.size()-1;i++){
			if(s[i]==s[i+1]) flag=true;
		}
		for(int i=0;!flag&&i<s.size()-2;i++){
			if(s[i]==s[i+2]) flag=true;
		}
		return flag;
	};
	if(f(a)) out1=(out1-1+mod)%mod;
	sum=(sum-out1+mod)%mod;

	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b;
	cin>>a>>b;
	cout<<solve(a,b)<<endl;
	return 0;
}