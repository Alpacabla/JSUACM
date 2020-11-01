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
int dp[405][205];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> num(n+1);
		for(int i=1;i<=n;i++){
			cin>>num[i];
		}
		memset(dp,0x3f3f,sizeof(dp));
		dp[0][0]=0;
		sort(num.begin()+1,num.end());
		num[0]=7;
		const int N=(n<<1);
		for(int i=1;i<=N;i++){
			int lim=min(i,n);
			dp[i][0]=0;		//初始化注意    以及其实可以变成一维数组
			for(int j=1;j<=lim;j++){
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+abs(i-num[j]));
			}
		}
		cout<<dp[N][n]<<endl;
	}
	return 0;
}