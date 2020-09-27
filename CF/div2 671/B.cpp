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
vector<ll> sum;
void init()
{
	ll now=1;
	ll x=2;
	for(int i=1;i<=31;i++){
		sum.push_back(now*(now+1)/2);
		now+=x;
		x<<=1;
		if(i!=1) sum[i-1]+=sum[i-2];
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	init();
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		int k=upper_bound(sum.begin(),sum.end(),n)-sum.begin();
		cout<<k<<endl;
	}
	return 0;
}
