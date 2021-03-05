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
bool vis[max_n];
int dp[max_n];
int pri[max_n],tot;
void init(int lim)
{
	for(int i=2;i<=lim;i++){
		if(!vis[i]){
			pri[tot++]=i;
		}
		for(int j=0;j<tot&&i*pri[j]<=lim;j++){
			vis[i*pri[j]]=true;
			if(i%pri[j]==0) break;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	init(100000);
	int t;
	cin>>t;
	while(t--){
		memset(dp,0,sizeof(dp));
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a.begin()+1,a.end());
		int max1=-1;
		for(int i=1;i<=n;i++){
			vector<int> p;
			for(int j=0;j<tot&&pri[j]*pri[j]<=a[i];j++){
				if(a[i]%pri[j]==0){
					p.push_back(pri[j]);
				}
				while(a[i]%pri[j]==0){
					a[i]/=pri[j];
				}
			}
			if(a[i]!=1){
				p.push_back(a[i]);
			}
			int maxx=-1;
			for(auto pp:p){
				maxx=max(dp[pp],maxx);
			}
			maxx++;
			for(auto pp:p){
				dp[pp]=maxx;
			}
		}
		for(int i=1;i<=100000;i++){
			max1=max(max1,dp[i]);
		}
		cout<<max1<<endl;
	}
	return 0;
}