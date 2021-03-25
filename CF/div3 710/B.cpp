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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		vector<int> dp(s.size()+10,int_inf);
		i=0;
		while(i<s.size()&&s[i]=='.') i++;
		if(i==s.size()){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		dp[i]=1;
		i++;
		int last=i-1;
		for(;i<s.size();i++){
			if(s[i]=='.') continue;
			for(int j=1;j<=m&&i-j>=0;j++){
				//if(s[j]=='*')
				dp[i]=min(dp[i-j]+1,dp[i]);
			}
			last=i;
		}
		cout<<dp[last]<<endl;
	}
	return 0;
}