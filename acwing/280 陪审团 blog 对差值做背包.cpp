/*
link: https://www.acwing.com/problem/content/description/282/
tags: 不同于普通背包的是对 差值(d) 当作容量进行dp，其实就是题意
	  但是我看不出来呜呜呜，因为普通的容量dp并不能从最优子结构到新的最优
	  但是差值就可以，因为我们并不在意数多大（这个可以靠dp值本身维护，且可转移）
	  只需要找最小的满足条件的差就行了。
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
int dp[205][22][805];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	
	int n,m;
	int now=0;
	while(cin>>n>>m){
		if(!n&&!m) break;
		now++;
		vector<int> p(n+1),d(n+1);
		for(int i=1;i<=n;i++){
			cin>>p[i]>>d[i];
		}
		for(int i=0;i<=n;i++){
			memset(dp[i],-1,sizeof(int)*(22)*(805));
		}
		dp[0][0][400]=0;
		for(int i=1;i<=n;i++){
				for(int j=400;j>=-400;j--){
					dp[i][0][j+400]=dp[i-1][0][j+400];
					for(int k=m;k>=1;k--){
						dp[i][k][j+400]=dp[i-1][k][j+400];
						if(j-(p[i]-d[i])+400>=0&&j-(p[i]-d[i])+400<=800&&dp[i-1][k-1][j-(p[i]-d[i])+400]!=-1){
							if(dp[i][k][j+400]<=dp[i-1][k-1][j-(p[i]-d[i])+400]+p[i]+d[i]){
								dp[i][k][j+400]=dp[i-1][k-1][j-(p[i]-d[i])+400]+p[i]+d[i];
							}
						}
					}
				}
		}
		bool flag=true;
		int ans=-1,dd=0;
		for(int i=0;i<=400&&flag;i++){
			flag=true;
			if(dp[n][m][400+i]!=-1){
				flag=false;
				dd=i;
				ans=dp[n][m][400+i];
			}
			if(dp[n][m][400-i]!=-1){
				flag=false;
				if(ans<dp[n][m][400-i]){
					dd=-i;
					ans=dp[n][m][400-i];
				}
			}
		}
		int k=400+dd;
		vector<int>out;
		while(m){
			if(dp[n][m][k]==dp[n-1][m][k]) n--; 
			else{
				out.push_back(n);
				k-=(p[n]-d[n]);
				n--;
				m--;
			}
		}
 		cout<<"Jury #"<<now<<endl;
		cout<<"Best jury has value "<<(ans+dd)/2<<" for prosecution and value "<<(ans-dd)/2<<" for defence:"<<endl;
		for(int i=out.size()-1;i>=0;i--){
			cout<<" "<<out[i];
		}
		cout<<endl;
		cout<<endl;
	}

	return 0;
}