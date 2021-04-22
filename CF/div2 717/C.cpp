// Problem: C. Baby Ehab Partitions Again
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
bool dp1[105][max_n],dp2[105][max_n];
int dp[105][max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int sum=0;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%2){
		cout<<"0"<<endl;
	}else{
		int k=sum/2;
		dp1[0][0]=true;
		for(int i=1;i<=n;i++){
			for(int j=0;j<a[i];j++) dp1[i][j]=dp1[i-1][j];
			for(int j=a[i];j<=k;j++){
				dp1[i][j]=dp1[i-1][j]?dp1[i-1][j]:dp1[i-1][j-a[i]];
			}
		} 
		dp2[n+1][0]=true;
		for(int i=n;i>=1;i--){
			for(int j=0;j<a[i];j++) dp2[i][j]=dp2[i+1][j];
			for(int j=a[i];j<=k;j++){
				dp2[i][j]=dp2[i+1][j]?dp2[i+1][j]:dp2[i+1][j-a[i]];
			}
		}
		if(!dp1[n][k]){
			cout<<0<<endl;
			return 0;
		}
		for(int i=1;i<=n;i++){
			int now=(sum-a[i])/2;
			bool flag=false;
			if((sum-a[i])%2){
				cout<<1<<endl;
				cout<<i<<endl;
				break;
			}
			for(int j=0;j<=now&&!flag;j++){
				if(dp1[i-1][j]&&dp2[i+1][now-j]){
					flag=true;
				}
			}
			if(!flag){
				cout<<1<<endl;
				cout<<i<<endl;
				break;
			}
		}
		//
	}
	return 0;
}