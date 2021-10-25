// Problem: F1. Korney Korneevich and XOR (easy version)
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/F1
// Memory Limit: 512 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
//#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=500+20;
int dp[max_n];
bool ans[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	memset(dp,0x3f,sizeof(dp));
	ans[0]=true;
	dp[0]=0;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=511;j++){
			if(dp[j]<=a[i]) continue;
			int v=j^a[i];
			if(dp[v]<a[i]){
				ans[j]=true;
				dp[j]=a[i];
			}
		}
	}
	vector<int> out;
	for(int i=0;i<=511;i++){
		if(ans[i]) out.push_back(i);
	}
	cout<<out.size()<<endl;
	for(auto a:out){
		cout<<a<<" ";
	}
	cout<<endl;
	return 0;
}