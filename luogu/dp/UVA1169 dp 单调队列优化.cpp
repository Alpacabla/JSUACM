/*
link: https://www.luogu.com.cn/problem/UVA1169
tags: 单调队列优化dp 当推出他转移的单调性时，就可以直接把所有东西揉到一起维护，也没有影响
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
#define dis(a,b) (abs(x[a]-x[b])+abs(y[a]-y[b]))
#define f(a,b) (dis(0,a)+dis(0,b)+condis[b]-condis[a])
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("data.txt","r",stdin);
	//freopen("Aout.txt","w",stdout);
	int i,j;
	int n,c;
	int t;
	cin>>t;
	while(t--){
		cin>>c>>n;
		vector<int> x(n+1),y(n+1),w(n+1),dp(n+1),condis(n+1),sum(n+1);
		x[0]=0;
		y[0]=0;
		w[0]=0;
		condis[0]=0;
		for(i=1;i<=n;i++){
			cin>>x[i]>>y[i]>>w[i];
			sum[i]=sum[i-1]+w[i];
			condis[i]=condis[i-1]+dis(i-1,i);
		}
		deque<int> q;
		dp[0]=0;
		q.push_back(0);
		for(i=1;i<=n;i++){
			while(!q.empty()&&sum[i]-sum[q.front()]>c){
				q.pop_front();
			}
			if(q.empty()){
				dp[i]=dp[i-1]+(dis(0,i)<<1);
			}else{
				dp[i]=dp[q.front()]+f(q.front()+1,i);
			}
			if(i==n) break;
			while(!q.empty()&&(dp[q.back()]+f(q.back()+1,i+1))>(dp[i]+f(i+1,i+1))){
				q.pop_back();
			}
			q.push_back(i);
		}
		cout<<dp[n]<<endl;
		if(t>0) cout<<endl;
	}
	return 0;
}
