// Problem: B. 攻防演练
// Contest: Codeforces - 2021年中国大学生程序设计竞赛女生专场
// URL: https://codeforces.com/gym/103389/problem/B
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
int nxt[max_n][26];
int dp[max_n][20];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>m>>n;
	string s;
	cin>>s;
	for(int i=0;i<m;i++){
		nxt[n][i]=n;
	}
	for(int i=0;i<20;i++){
		dp[n][i]=n;
	}
	for(int i=s.size()-1;i>=0;i--){
		for(int j=0;j<m;j++){
			nxt[i][j]=nxt[i+1][j];
		}
		nxt[i][s[i]-'a']=i;
		for(int j=0;j<m;j++){
			dp[i][0]=max(dp[i][0],nxt[i][j]);
		}
	}
	for(int i=1;i<20;i++){
		for(int j=0;j<n;j++){
			dp[j][i]=dp[min(dp[j][i-1]+1,n)][i-1];
		}
	}
	int q;
	cin>>q;
	while(q--){
		int l,r;
		cin>>l>>r;
		l--,r--;
		int ans=0;
		for(int i=19;i>=0;i--){
			int tr=dp[l][i];
			if(tr<=r){
				l=tr+1;
				ans+=(1<<i);
			}
			if(l>r) break;
		}
		cout<<ans+1<<endl;
	}
	return 0;
}