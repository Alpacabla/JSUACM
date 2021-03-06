/*
link: https://www.acwing.com/problem/content/316/
tags: (要记得多利用已知信息)
	  最重要的是要知道如果 i<j && num[i]==num[j] && dp[i]==dp[j]
	  那么题目求的贡献数里i位置的贡献被包含在j位置的贡献里

	  所以有两种做法，一种是直观的用一个set来判重
	  并且lis里的判断可以反过来从i到1，这样第一个被取到j的贡献就是全部贡献O(n^2 * logn)
	  这个方法不太好

	  第一种是对于这个贡献也来做一遍递推，当存在有j前面的i符合上面的式子的时候直接让j位置贡献清0，因为都是重复的
	  这样递推最后再计数一定是正确的O(n^2)
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#pragma GCC optimize(2)
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=5e3+5;
int dp[max_n];
ll cnt[max_n];
set<ll>sets[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	vector<ll> num(n+1);
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	num[0]=ll_inf;
	dp[0]=0;
	cnt[0]=1;
	for(int i=1;i<=n;i++){
		sets[i].clear();
		for(int j=i-1;j>=0;j--){
			if(num[i]<num[j]){
				if(dp[i]<=dp[j]+1){
					if(dp[i]==dp[j]+1){
						if(!sets[i].count(num[j])){
							cnt[i]+=cnt[j];
							sets[i].insert(num[j]);
						}
					}else{
						dp[i]=dp[j]+1;
						sets[i].clear();
						cnt[i]=cnt[j];
						sets[i].insert(num[j]);
					}
				}
			}
		}
	}
	int ans1=0;
	ll ans2=0;
	for(int i=1;i<=n;i++){
		if(ans1<dp[i]){
			ans1=dp[i];
		}
	}
	set<ll>ans_set;
	for(int i=n;i>=1;i--){
		if(dp[i]==ans1){
			if(!ans_set.count(num[i])){
				ans_set.insert(num[i]);
				ans2+=cnt[i];
			}
		}
	}
	cout<<ans1<<" "<<ans2<<endl; 
	return 0;
}