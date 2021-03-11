/*
link: 
tags: 细节有点多，但是其实并不难呜呜呜。只要存在一个
      唯一的对称最高山峰就行了，并且高度得是奇数
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
	int max2=-1;
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			dp1[i]=dp1[i-1]+1;
		}
	}
	int ind=-1;
	for(int i=n-1;i>=1;i--){
		if(a[i]>a[i+1]){
			dp2[i]=dp2[i+1]+1;
		}
		if(dp2[i]==dp1[i]){
			if(max1<dp2[i]){
				max1=dp2[i];
				ind=i;
			}
		}else{
			max2=max(max2,dp2[i]);
			dp1[i]=0;
		}
	}
	memset(dp2,0,sizeof(int)*(n+3));
	for(int i=2;i<=n;i++){
		if(a[i]>a[i-1]){
			dp2[i]=dp2[i-1]+1;
		}
		if(ind!=i){
			max2=max(max2,dp2[i]);
		}
	}
	if(max1%2==0&&max1&&max1>max2) cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}