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
const int max_n=3e3+5;
int dp[max_n][max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1,s2;
	cin>>s1>>s2;
	s1="1"+s1;
	s2=" "+s2;
	for(int i=1;i<s1.size();i++){
		for(int j=1;j<s2.size();j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(s1[i]==s2[j]) dp[i][j]=dp[i-1][j-1]+1;
		}
	}
	int now=dp[s1.size()-1][s2.size()-1];
	int y=s2.size()-1;
	string ans="";
	int k=s1.size()-1;
	for(int i=s1.size()-1;now&&i>=0;i--){
		int last=-1;
		for(int j=1;!(~last)&&j<=y;j++){
			if(dp[i][j]==now){
				last=j;
			}
		}  
		if(last==-1){
			now--;
			ans+=s2[k];
			y=k-1;
			i++;
		}else{
			k=last;
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<ans<<endl;
	return 0;
}