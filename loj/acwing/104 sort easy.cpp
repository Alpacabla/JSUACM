/*
link: https://www.acwing.com/problem/content/106/
tags: sort
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
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num,num+n);
	int mid=num[n/2];
	ll sum=0;
	for(i=0;i<n;i++){
		sum+=abs(mid-num[i]);
	}
	cout<<sum<<endl;
	return 0;
}
