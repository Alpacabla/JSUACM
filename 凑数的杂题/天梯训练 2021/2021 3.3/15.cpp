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
	ll ans=0;
	int n;
	cin>>n;
	vector<int> a(n+2);
	vector<int> hi(n+2);
	for(int i=1;i<=n;i++) cin>>a[i];
	a[0]=-1;
	a[n+1]=int_inf;
	for(int i=1;i<=n;i++){
		if(a[i]>a[i-1]) hi[i]=hi[i-1]+1;
		else hi[i]=1;
	}
	for(int i=n;i>=1;i--){
		if(a[i]>a[i+1]) hi[i]=max(hi[i],hi[i+1]+1);
		ans+=hi[i];
	}
	cout<<ans<<endl;
	return 0;
}