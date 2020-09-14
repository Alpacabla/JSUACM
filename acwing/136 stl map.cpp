/*
link: https://www.acwing.com/activity/content/problem/content/371/1/
tags: map stl easy
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=2e9+3;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	//cout<<int_inf<<endl;
	map<int,int>mp;
	mp[-int_inf]=0;
	mp[int_inf]=0;
	int n;
	cin>>n;
	int num;
	cin>>num;
	mp[num]=1;
	for(i=2;i<=n;i++){
		cin>>num;
		auto it=mp.lower_bound(num);
		auto ansit=--it;
		it++;
		if(abs((it->first)-num)<abs((ansit->first)-num)){
			cout<<abs((it->first)-num)<<" "<<(it->second)<<endl;
		}else{
			cout<<abs((ansit->first)-num)<<" "<<(ansit->second)<<endl;
		}
		mp[num]=i;
	}
	return 0;
}
