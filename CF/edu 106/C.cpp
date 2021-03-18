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
		ll ans=ll_inf;
		cin>>n;
		vector<ll> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ll min1=a[1],min2=ll_inf;
		ll sum1=0,sum2=0;
		ll len1=1,len2=0;
		for(int i=2;i<=n;i++){
			if(i%2==0){
				if(a[i]<min2){
					if(min2!=ll_inf) sum2+=min2;
					min2=a[i];
				}else{
					sum2+=a[i];
				}
				len2++;
			}else{
				if(a[i]<min1){
					sum1+=min1;
					min1=a[i];
				}else{
					sum1+=a[i];
				}
				len1++;
			}
			ans=min(ans,(n-len1+1)*min1+sum1+(n-len2+1)*min2+sum2);
		}
		cout<<ans<<endl;
	}
	return 0;
}