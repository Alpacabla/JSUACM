/*
link: https://www.luogu.com.cn/problem/P1908
tags: 树状数组求逆序对(二维偏序)
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
const int max_n=5e5+5;
int bit[max_n];
void add(int ind,const int a)
{
	while(ind){
		bit[ind]+=a;
		ind-=lowbit(ind);
	}
	return ;
}
int query(int ind,const int n)
{
	int res=0;
	while(ind<=n){
		res+=bit[ind];
		ind+=lowbit(ind);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	int a;
	cin>>n;
	vector<int> num(n);
	for(i=0;i<n;i++) cin>>num[i];
	vector<int> uni(num);
	sort(uni.begin(),uni.end());
	unique(uni.begin(),uni.end());
	ll ans=0;
	for(i=0;i<n;i++){
		int k=lower_bound(uni.begin(),uni.end(),num[i])-uni.begin();
		ans+=1ll*query(k+1,n);
		add(k,1);
	}
	cout<<ans<<endl;
	return 0;
}
