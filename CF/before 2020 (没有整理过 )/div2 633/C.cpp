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
const int max_n=3e5+5;
ll a[max_n],b[max_n],d[max_n];
int main()
{
  	int t;
  	int i,j;
  	ll n;
  	cin>>t;
  	while(t--){
  		scanf("%lld",&n);
  		ll sum=0;
  		a[0]=b[0]=0;
  		for(i=1;i<=n;i++){
  			scanf("%lld %lld",a+i,b+i);
  			sum+=a[i];
  		}
  		b[0]=b[n];
  		for(i=1;i<=n;i++){
  			d[i]=(b[i-1]>=a[i])?a[i]:b[i-1];
  			sum-=d[i];
  		}
  		ll ans=INF;
  		for(i=1;i<=n;i++){
  			ans=min(ans,sum+d[i]);
  		}
  		printf("%lld\n",ans);
  	}
	return 0;
}