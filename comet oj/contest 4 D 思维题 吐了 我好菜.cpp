/*
link: https://cometoj.com/contest/39/problem/D?problem_id=1584
tags: 脑筋急转弯思维题呜呜呜 还以为数位dp呢，我好拉啊
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
ll get(ll n,bool flag)
{
	vector<ll> num;
	if(n==0) num.push_back(0);
	while(n){
		num.push_back(n%10);
		n/=10;
	}
	reverse(num.begin(),num.end());
	while(num.size()>1){
		for(int i=0;i<num.size()-1;i++){
			num[i]=(num[i]+num[i+1])%10;
		}
		num.pop_back();
		while(num.size()&&num[0]==0){
			num.erase(num.begin());
		}
		if(num.size()==0) num.push_back(0);
	}
	return num[0];
}
ll solve(ll n)
{
	ll k=n/10;
	//if(k<0) k=0;
	ll res=k*45;
	//k++;
	k*=10;
	ll add=get(k,1);
	res+=add;
	int cnt=0;
	k++;
	while(k<=n){
		cnt++;
		res+=(add+cnt)%10;
		k++;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	for(ll i=1;i<=100;i++){
		if(get(i,1)!=get(i,0)){
			cout<<i<<endl;
			return 0;
		}
	}
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		a--;
		cout<<solve(b)-solve(a)<<endl;
	}
	return 0;
}