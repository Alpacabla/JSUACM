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
		vector<ll> a(n+2),b(n+2),c(n+2),d(n+2);
		int k;
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
			if(a[i]>b[i]){
				swap(a[i],b[i]);
			}
			d[i]=b[i]-a[i];
		}
		ll ans=0;
		ll sum=0;
		int l=1;
		for(int i=2;i<=n;i++){
			ans=max(ans,c[i]-1+(i-l)*2+d[l+1]+sum);
			sum+=c[i]-1-d[i+1];
			if(i!=n&&(d[i+1]-d[l+1]>(i-l)*2+sum)){
				l=i;
				sum=0;
			}
			if(i!=n&&d[i+1]==0){
				l=i;
				sum=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}