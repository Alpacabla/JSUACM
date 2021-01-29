#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
int num[max_n<<1];
ll sum[max_n<<1],xsum[max_n<<1];
int check(int l,int r,ll num)
{
	int res;
	int k=l-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(sum[mid]-sum[k]>=num){
			res=mid;
			r=mid-1;
			//cout<<res<<endl;
		}else{
			l=mid+1;
		}
		//cout<<l<<" "<<r<<endl;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	ll x;
	int n;
	cin>>n>>x;
	for(i=1;i<=n;i++){
		cin>>num[i];
		sum[i]=sum[i-1]+num[i];
		xsum[i]=xsum[i-1]+((ll)num[i]+1)*num[i]/2;
	}
	int lim=n<<1;
	for(i=n+1;i<=lim;i++){
		num[i]=num[i-n];
		sum[i]=sum[i-1]+num[i];
		xsum[i]=xsum[i-1]+((ll)num[i]+1)*num[i]/2;
	}
	ll ans=-1;
	for(i=1;i<=n;i++){
		int ind=check(i,lim,x);
		//cout<<"i "<<i<<endl;
		//cout<<ind<<endl;
		ll d=num[ind]-(sum[ind]-sum[i-1]-x);
		//cout<<"d "<<d<<endl;
		ll min1=min(num[ind]-d,(ll)num[i]);
		//cout<<"min1 "<<min1<<endl;
		ll res=0;
		res=xsum[ind-1]-xsum[i-1];
		//cout<<res<<endl;
		res+=(d+1)*d/2;
		res-=(min1+1)*min1/2;
		res+=(d+1+d+min1)*min1/2;
		//cout<<res<<endl;
		ans=max(ans,res);
		//num[ind]-d;
		//int k=lowwer_bound(pre+1,pre+1+1000000,d)-pre;
	}
	cout<<ans<<endl;
	return 0;
}