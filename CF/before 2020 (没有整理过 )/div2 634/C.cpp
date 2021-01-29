#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
ll dp[max_n];
ll pow_2[50];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int now=0;
		cin>>dp[1];
		for(i=2;i<=n;i++){
			cin>>dp[i];
			if(dp[i]<dp[i-1]){
				ll d=dp[i-1]-dp[i];
				int cnt=0;
				while(d){
					d>>=1;
					cnt++;
				}
				dp[i]=dp[i-1];
				now=max(cnt,now);
			}
		}
		cout<<now<<endl;
	}
	return 0;
}