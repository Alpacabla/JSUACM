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
struct node{
	ll v;
	int ind;
	bool operator < (const node & a) const {
		return v<a.v;
	}
};
vector<node> cnt[20];
ll xx[20];
void init()
{
	ll x=1;
	int i;
	xx[0]=1;
	for(i=1;i<=18;i++){
		xx[i]=xx[i-1]*10;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	ll n;
	int m;
	init();
	cin>>n>>m;
	for(i=0;i<m;i++){
		int a;
		ll b;
		cin>>a>>b;
		cnt[a].push_back((node){b*xx[a],i+1});
	}
	int now=0;
	bool flag=true;
	vector<int> ans;
	priority_queue<node> q;
	ll sum=0;
	while(n){
		if(now==19){
			break;
		}
		ll e;
		ll t=0;
		if(now<=17){
			e=n%xx[now+1];
		}else e=n;
		for(i=0;i<cnt[now].size();i++){
			q.push(cnt[now][i]);
		}
		while(!q.empty()){
			if(sum>=e){
				break;
			}
			sum+=q.top().v;
			ans.push_back(q.top().ind);
			q.pop();
		}
		now++;
		if(sum<e){
			flag=false;
			break;
		}
	}
	if(!flag||sum<e){
		cout<<-1<<endl;
		return 0;
	}
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
