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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> num(n);
		ll sum=0;
		int max1=-1;
		for(int i=0;i<n;i++){
			cin>>num[i];
			sum+=num[i];
			max1=max(max1,num[i]);
		}
		ll ans=0;
		if(sum%(n-1)==0){
			ll k=sum/(n-1);
			if(k<max1){
				ans+=(max1-k)*(n-1);
			}
			cout<<ans<<endl;
		}else{
			ll d=(n-1)-sum%(n-1);
			ans+=d;
			sum+=d;
			ll k=sum/(n-1);
			if(k<max1){
				ans+=(max1-k)*(n-1);
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}