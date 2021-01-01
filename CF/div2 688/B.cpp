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
		int n,m;
		cin>>n;
		vector<int> a(n+2),d(n+2);
		int ans=0;
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		a[n+1]=a[n-1];
		a[0]=a[1];
		for(int i=1;i<=n;i++){
			d[i]=a[i]-a[i-1];
			if(d[i]!=0) flag=false;
		}
		if(flag) cout<<0<<endl;
		else {
			ll ans=0;
			int max1=-1;
			for(int i=1;i<=n;i++){
				ans+=abs(d[i]);
			}
			//cout<<"ok"<<endl;
			//cout<<ans<<endl;
			ll out=ll_inf;
			d[n+1]=0;
			a[0]=a[2];
			for(int i=1;i<=n;i++){
				out=min(out,ans-abs(d[i])-abs(d[i+1])+abs(a[i+1]-a[i-1]));
				//cout<<ans-abs(d[i])-abs(d[i+1])+abs(a[i+1]-a[i-1])<<endl;
				//out=min(out,ans-d[i+1]-d[i]+())
			}
			cout<<out<<endl;
		}
	}
	return 0;
}