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
const int max_n=2e5+5;
bool vis[max_n];
int tot=0;
int pri[max_n];
void init()
{
	for(int i=2;i<=200000;i++){
		if(!vis[i]){
			pri[tot++]=i;
		}
		for(int j=0;j<tot&&pri[j]*i<=200000;j++){
			vis[pri[j]*i]=true;
			if(i%pri[j]==0){
				break;
			}
		}
	}
	return ;
}
map<int,int> mp[max_n];
multiset<int> sets[max_n];
ll res=1;
int minn[max_n];
int n;
const ll mod=1e9+7;
inline void push(int last,int now,int prime){
	if(last==0){
		sets[prime].insert(now);
		if(sets[prime].size()==n){
			int min1=*(sets[prime].begin());
			if(min1>minn[prime]&&sets[prime].size()==n){
				int cnt=min1-minn[prime];
				minn[prime]=min1;
				for(int i=0;i<cnt;i++){
					res=res*prime%mod;
				}
			}
		}
		return ;
	}
	sets[prime].erase(sets[prime].find(last));
	sets[prime].insert(now);
	int min1=*(sets[prime].begin());
	if(min1>minn[prime]&&sets[prime].size()==n){
		int cnt=min1-minn[prime];
		minn[prime]=min1;
		for(int i=0;i<cnt;i++){
			res=res*prime%mod;
		}
	}
	return ;
}
void multi(int ind,int a)
{
	for(int i=0;i<tot&&pri[i]*pri[i]<=a&&a!=1;i++){
		if(a%pri[i]==0){
			int cnt=0;
			int last=mp[ind][pri[i]];
			while(a%pri[i]==0){
				a/=pri[i];
				cnt++;
			}
			mp[ind][pri[i]]+=cnt;
			//cout<<'k'<<endl;
			push(last,last+cnt,pri[i]);
		}
	}
	if(a!=1){
		//cout<<'a'<<a<<endl;
		int last=mp[ind][a];
		mp[ind][a]+=1;
		push(last,last+1,a);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int q;
	init();
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		multi(i,a);
	}
	for(int i=0;i<q;i++){
		int ind,a;
		cin>>ind>>a;
		multi(ind,a);
		cout<<res<<endl;
	}
	return 0;
}