/*
link: https://www.acwing.com/problem/content/320/
tags: dp傻瓜题
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
	int a[7];
	while(cin>>a[1]){
		for(int i=2;i<=6;i++) cin>>a[i];
		bool flag=true;
		int val=0;
		for(int i=1;i<=6;i++){
			if(a[i]) flag=false; 
			val+=a[i]*i;
		}
		if(flag) break;
		flag=true;
		if(val%2==0){
			vector<bool> dp(val/2+1);
			dp[0]=true;
			val/=2;
			for(int i=1;i<=6;i++){
				for(int j=0;j<i;j++){
					if(dp[j]){
						int last=0;
						for(int k=j;k<=val;k+=i){
							if(dp[k]) last=k;
							if((k-last)/i>a[i]) dp[k]=false;
							else dp[k]=true;
						}
					}
				}
			}
			flag=dp[val];
		}else flag=false;
		if(flag) cout<<"Can"<<endl;
		else cout<<"Can't"<<endl;
	}
	return 0;
}