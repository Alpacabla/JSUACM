/*
link: https://www.acwing.com/problem/content/102/
tags: chafen
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
ll d[max_n],num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>num[i];
		d[i]=num[i]-num[i-1];
	}
	ll a=0,b=0;
	for(i=2;i<=n;i++){
		if(d[i]>0){
			a+=d[i];
		}
		if(d[i]<0){
			b-=d[i];
		}
	}
	cout<<min(a,b)+abs(a-b)<<endl;
	cout<<abs(a-b)+1<<endl;
	return 0;
}