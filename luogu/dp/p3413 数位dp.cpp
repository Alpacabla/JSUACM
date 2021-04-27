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
vector<int> EMPTY(11,0);
vector<int> dp[max_n][15];
vector<int> dfs(vector<int> &a,int now,int pre,bool flag)
{
	if(now==0) return EMPTY;
	if(!flag&&dp[now][pre].size()) return dp[now][pre];
	int lim=flag?a[now]:9;
	vector<int> res(11);
	for(int i=0;i<=lim;i++){
		if(pre==i) continue;
		vector<int> zz=dfs(a,now-1,i==0&&pre==ZERO?ZERO:i,i==lim&&flag);
		//if(zz.size()){
		for(int j=0;j<=10;j++){
			if(pre==j) continue;
			res[i]=(res[i]+zz[j])%mod;
		}
		//}
	}
	return !flag&&pre!=ZERO?dp[now][pre]=res:res;
}
void init()
{
	EMPTY[10]=1;
	// vector<int> num(11,0);
	// num[10]=1;
	// for(int i=0;i<=9;i++){
	// 	dp[0][i]=num;
	// }
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	string a,b;
	cin>>a>>b;
	vector<int> aa(a.size()+1),bb(b.size()+1);
	for(int i=0;i<a.size();i++){
		aa[i]=a[i]-'0';
	}
	aa[a.size()]=ZERO;
	for(int i=0;i<b.size();i++){
		bb[i]=b[i]-'0';
	}
	bb[b.size()]=ZERO;

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

	vector<int> ans1=dfs(aa,aa.size()-1,ZERO,true);
	int out1=0;
	for(int i=0;i<=9;i++){
		out1=(out1+ans1[i])%mod;
	}
	vector<int> ans2=dfs(bb,bb.size()-1,ZERO,true);
	int out2=0;
	for(int i=0;i<=9;i++){
		out2=(out2+ans2[i])%mod;
	}
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
	cout<<sum<<endl;
	return 0;
}