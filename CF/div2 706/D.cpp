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
int a[max_n];
int dp1[max_n],dp2[max_n];
int dp11[max_n],dp22[max_n];
int main()
{
	int i,j;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int max1=-1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			dp1[i]=dp1[i-1]+1;
		}
	}
	for(int i=n-1;i>=1;i--){
		if(a[i]>a[i+1]){
			dp2[i]=dp2[i+1]+1;
		}
		if(dp2[i]!=dp1[i]&&!((max(dp2[i],dp1[i])==2)&&min(dp2[i],dp1[i])==1)){
			dp1[i]=0;
			continue;
		}
		dp1[i]=min(dp1[i],dp2[i]);
		max1=max(max1,dp1[i]);
	}
	int max2=-1;
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1]){
			dp11[i]=dp11[i-1]+1;
		}
	}
	set<int> sets;
	for(int i=n-1;i>=1;i--){
		if(a[i]<a[i+1]){
			dp22[i]=dp22[i+1]+1;
		}
		dp11[i]=max(dp11[i],dp22[i]);
		max2=max(max1,dp11[i]);
		//cout<<dp11[i]<<endl;
		sets.insert(dp11[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int k=dp1[i];
		if(k%2==1) continue;
		auto x=sets.upper_bound(k+1);
		if(x==sets.end()){
			//cout<<i<<endl;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}