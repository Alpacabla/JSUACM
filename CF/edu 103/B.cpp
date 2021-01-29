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
#define ESP 1e-7
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		ll add=0;
		ll sum=0,k;
		cin>>n>>k;
		double lim=k/100.0;
		cin>>sum;
		//long double max=-1.0;
		for(int i=1;i<n;i++){
			ll p;
			cin>>p;
			ll r=p*100;
			if(r%k==0) r/=k;
			else r=r/k+1;
			add=max(add,r-sum);
			//cout<<r<<endl;
			// if(r-lim>ESP){
			// 	add+=(ll)(ceil((p*1.0)/lim)-sum);
			// 	//add=max(add,(ll)(ceil((p*1.0)/lim)-sum));
			// 	sum=(ll)(ceil((p*1.0)/lim));
			// }
			sum+=p;
		}
		cout<<add<<endl;
	}
	return 0;
}