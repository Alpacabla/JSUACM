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
bool dp[10005][105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1); 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end(),[](const int b,const int c) -> bool{
		return b>c;
	});
	dp[0][0]=true;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=100;j++){
			dp[i][j]=dp[i-1][j];
		}
		for(int j=a[i];j<=100;j++){
			if(dp[i-1][j-a[i]]){
				dp[i][j]=dp[i-1][j-a[i]];
			}
		}
	}
	if(dp[n][m]){
		//cout<<1<<" ";
		int now=n;
		bool flag=true;
		while(now&&m){
			if(dp[now-1][m-a[now]]){
				m-=a[now];
				if(flag) cout<<a[now];
				else cout<<" "<<a[now];
				flag=false;
			}
			now--;
		}
		cout<<endl;
	}else{
		cout<<"No Solution"<<endl;
	}
	return 0;
}