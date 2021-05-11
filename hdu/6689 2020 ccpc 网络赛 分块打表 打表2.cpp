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
const int sqn=1e5;
const ll lim=1e10;
#define TEST 20
ll sum[max_n];
int tot;
vector<ll>pri(lim/10);
bitset<lim+5>ispri;
void euler()
{
	static int tot=0;
	ispri[1]=0;
	for(ll i=2;i<=lim;i++){
		if(!ispri[i]){
			pri[tot++]=i;
			cout<<i<<endl;
		}
		for(int j=0;j<tot&&i*pri[j]<=lim;j++){
			ispri[i*pri[j]]=true;
			if(i%pri[j]==0) break;
		}
	}
	return ;
}
bool is_prime(ll num)
{
	return !ispri[num];
}
void init()
{
	ll now=0;
	for(ll i=1;i<=lim;i++){
		if(is_prime(i)){
			now+=i;
		}
		if(i%sqn==0){
			sum[++tot]=now;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	srand(time(0));
	int t;
	//freopen("test1.out","w",stdout);
	//cout<<"ll sum[]={0";
	euler();
	init();
	for(int i=1;i<=sqn;i++){
		//cout<<","<<sum[i];
		if(i%(sqn/10)==0) cout<<endl;
	}
	//cout<<"}";
	//cout<<endl;
	return 0;
}