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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		sort(a.begin()+1,a.end());
		vector<int> d(n);
		for(int i=2;i<=n;i++){
			d[i-1]=a[i]-a[i-1];
		}
		n--;
		ll ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=1ll*d[i]*i*(n+1-i);
			ans+=1ll*d[n+1-i]*i*(n+1-i);
		}
		if(n%2==1){
			ans+=1ll*d[(n+1)/2]*(n+1)/2*(n+1)/2;
		}
		cout<<a[a.size()-1]-ans<<endl;
	}
	return 0;
}