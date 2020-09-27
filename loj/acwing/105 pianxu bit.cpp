/*
link: https://www.acwing.com/problem/content/109/
tags: bit partial order偏序
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
int n;
inline void add(int a,const int b){
	while(a){
		bit[a]+=b;
		a-=lowbit(a);
	}
	return ;
}
inline ll query(int a){
	ll res=0;
	while(a<=n){
		res+=bit[a];
		a+=lowbit(a);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	//int n;
	while(cin>>n){
		if(n==0){
			break;
		}
		for(i=1;i<=n;i++) bit[i]=0;
		ll ans=0;
		vector<int>num(n);
		for(i=0;i<n;i++){
			cin>>num[i];
		}
		vector<int>a(num);
		sort(num.begin(),num.end());
		unique(num.begin(),num.end());
		for(i=0;i<n;i++){
			int k=lower_bound(num.begin(),num.end(),a[i])-num.begin()+1;
			add(k,1);
			ans+=query(k+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
