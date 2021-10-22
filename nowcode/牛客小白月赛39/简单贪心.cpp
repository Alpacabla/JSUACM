/*
link: 
tags: 
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n+5);
	vector<ll> sum(n+5),esum(n+5);
	for(int i=2;i<=n+1;i++){
		cin>>a[i];
	}
	vector<int> b=a;
	for(int i=2;i<=n+1;i++){
		int add=0;
		if(b[i]>0){
			add=b[i];
			b[i+1]-=b[i];
			b[i+2]-=b[i];
			b[i]=0;
		}
		sum[i]=sum[i-1]+add;
	}

	b=a;
	for(int i=n+1;i>=2;i--){
		int add=0;
		if(b[i]>0){
			add=b[i];
			b[i-1]-=b[i];
			b[i-2]-=b[i];
			b[i]=0;
		}
		esum[i]=esum[i+1]+add;
	}
	ll ans=ll_inf;
	for(int i=1;i<=n+1;i++){
		ans=min(ans,sum[i]+esum[i+2]);
	}
	cout<<ans<<endl;
	return 0;
}