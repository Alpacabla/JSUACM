#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
ll sum1[max_n],sum2[max_n];
int n,k;
ll a[max_n],d[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	int i,j;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[0]=a[1];
	for(i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	i=1;
	ll t,cnt=0;
	while(i<=n){
		t=a[i];
		cnt=0;
		while(i<=n&&t==a[i]){
			i++;
			cnt++;
		}
		if(cnt>=k){
			cout<<0<<endl;
			return 0;
		}
	}
	sum1[0]=0;
	sum2[0]=0;
	d[n+1]=0;
	for(i=1;i<=n;i++){
		sum1[i]+=sum1[i-1]+(ll)d[i]*(i-1);
		sum2[i]+=sum2[i-1]+(ll)d[n-i+2]*(i-1);
	}
	i=k;
	while(i<n&&a[i]==a[i+1]){
		i++;
	}
	j=n-k+1;
	while(j>=2&&a[j]==a[j-1]){
		j--;
	}
	ll ans=min(sum1[k]-(i-k),sum2[k]-(n-k+1-j));
	for(i=1;i<=n;i++){
		//cout<<sum1[i]<<" "<<sum2[n-i+1]<<" "<<sum1[i]+sum2[n-i+1]-(n-k)<<endl;
		if(sum1[i]+sum2[n-i+1]-(n-k)>=0) ans=min(ans,sum1[i]+sum2[n-i+1]-(n-k));
		else ans=0;
		//ans=min(ans,sum2[i]+sum1[k-i]-(n-k));
	}
	cout<<ans<<endl;
	return 0;
}