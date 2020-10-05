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
ll book[105][105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cin>>book[i][j];
			}
		}
		ll ans=0;
		int lim1=n/2;
		int lim2=m/2;
		if(n%2) lim1++;
		if(m%2) lim2++;
		for(i=1;i<=lim1;i++){
			for(j=1;j<=lim2;j++){
				vector<ll> a;
				a.push_back(book[i][j]);
				a.push_back(book[n-i+1][j]);
				a.push_back(book[n-i+1][m-j+1]);
				a.push_back(book[i][m-j+1]);
				//ll sum=book[i][j]+book[n-i+1][j]+book[n-i+1][m-j+1]+book[i][m-j+1];
				sort(a.begin(),a.end());
				if(j==m-j+1||i==n-i+1){
					ans+=a[2]-a[1];
				}else
				ans+=(a[1]-a[0])+a[2]-a[1]+a[3]-a[1];
				//cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
