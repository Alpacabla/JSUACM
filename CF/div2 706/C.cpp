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
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int i,j;
	long double ans;
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<long double> a(n),b(n);
		int cnt1=0,cnt2=0;
		for(i=1;i<=n*2;i++){
			long double x,k;
			scanf("%Lf%Lf",&k,&x);
			if(x<0) x=abs(x);
			if(k<0) k=abs(k);
			if(k==0){
				a[cnt1++]=x;
			}else{
				b[cnt2++]=k;
			}
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		ans=0.0;
		for(int i=n-1;i>=0;i--){
			//cout<<a[i]<<endl;
			ans+=sqrt(a[i]*a[i]+b[n-1-i]*b[n-1-i]);
		}
		long double ans1=0.0;
		for(int i=0;i<=n-1;i++){
			ans1+=sqrt(a[i]*a[i]+b[i]*b[i]);
		}
		ans=min(ans,ans1);
		printf("%.16Lf\n",ans);
	}
	return 0;
}