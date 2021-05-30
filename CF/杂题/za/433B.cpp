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
	int n;
	cin>>n;
	vector<int> a(n+1),b(n+1);
	vector<ll> sum1(n+1),sum2(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b.begin()+1,b.end());
	for(int i=1;i<=n;i++){
		sum1[i]=sum1[i-1]+a[i];
		sum2[i]=sum2[i-1]+b[i];
	}
	int m;
	cin>>m;
	while(m--){
		int x,l,r;
		cin>>x>>l>>r;
		if(x==1){
			cout<<sum1[r]-sum1[l-1]<<endl;
		}else{
			cout<<sum2[r]-sum2[l-1]<<endl;
		}
	}
	return 0;
}