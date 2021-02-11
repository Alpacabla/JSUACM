/*
link: https://www.acwing.com/problem/content/318/
tags: 简单dp，想太复杂了，就是每个元素都可以是加或者减，除了前几个有限制
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
const int max_n=2e4+5;
const int shift=1e4;
bool dp[105][max_n];
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(0);
    int n,t;
    cin>>n>>t;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    }
    dp[1][a[1]+shift]=true;
    for(int i=2;i<=n;i++){
    	for(int j=-shift;j<=shift;j++){
    		if(j+a[i]+shift>=0&&j+a[i]<=shift&&!dp[i][j+shift]) dp[i][j+shift]=dp[i-1][j+a[i]+shift];
    		if(i>=3&&j-a[i]+shift>=0&&j-a[i]<=shift&&!dp[i][j+shift]) dp[i][j+shift]=dp[i-1][j-a[i]+shift];
    	}
    }
    int now=n;
    vector<int> ans;
    t+=shift;
    bool flag=false;
    int cnt=0;
   	while(now!=1){
   		if(dp[now-1][t-a[now]]){
   			t-=a[now];
   			if(!flag){
   				ans.push_back(1);
   				flag=true;
   			}
   			ans.push_back(2);
   		}else if(dp[now-1][t+a[now]]){
   			t+=a[now];
   			if(flag){
   				flag=false;
   			}else{
   				ans.push_back(1);
   			}
   		}
   		now-=1;
   	}
   	for(int i=ans.size()-1;i>=0;i--){
   		cout<<ans[i]<<endl;
   	}
    return  0;
}