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
const int max_n=2e5+5;
ll n1[max_n],n2[max_n];
bool judge(ll lim,const int n)
{
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(n1[i]>lim) sum+=n2[i];
	}
	return sum<=lim;
}
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
		for(int i=1;i<=n;i++){
			cin>>n1[i];
		}
		for(int i=1;i<=n;i++){
			cin>>n2[i];
		}
		ll l=1,r=1e9,mid,ans;
		while(l<=r){
			int mid=(l+r)>>1;
			if(judge(mid,n)){
				ans=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}