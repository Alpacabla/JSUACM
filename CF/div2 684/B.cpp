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
		int n,k;
		cin>>n>>k;
		int sum=n*k;
		vector<ll> num(sum+1);
		for(int i=1;i<=sum;i++){
			cin>>num[i];
		}
		ll ans=0;
		int d=(n)/2;
		for(int i=sum-d,j=1;i>=1&&j<=k;i-=d+1,j++){
			ans+=num[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}