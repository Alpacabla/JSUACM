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
int pri[max_n],tot;
bool vis[max_n];
void init(const int lim)
{
	for(int i=2;i<=lim;i++){
		if(!vis[i]){
			pri[tot++]=i;
		}
		for(int j=0;j<tot&&pri[j]*i<=lim;j++){
			vis[i*pri[j]]=true;
			if(i%pri[j]==0) break;
		}
	}
	return ;
}
vector<int>num,cnt;
vector<vector<int> >ans;
void dfs(int n)
{
	
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	init((int)1e5+3);
	cin>t;
	whiel(t--){
		int n;
		cin>>n;
		ans.clear(),num.clear();
		int k=n;
		for(i=0;i<tot&&pri[i]*pri[i]<=n;i++){
			if(n%pri[i]==0){
				num.push_back(pri[i]);
				int cnt1=0;
				while(n%pri[i]==0){
					cnt1++;
					n/=pri[i];
				}
				cnt.push_back(cnt1);
			}
		}
		dfs();
	}
	return 0;
}
