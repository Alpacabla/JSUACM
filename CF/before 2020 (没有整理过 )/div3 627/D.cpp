#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int max_n=2e5+10;
int a[max_n];
int main()
{
	int n,t;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d",a+i);
	for(i=0;i<n;i++){
		scanf("%d",&t);
		a[i]=a[i]-t;
	}
	sort(a,a+n);
	int l,r,mid;
	ll ans=0;
	int cnt=0;
	for(i=0;i<n-1;i++){
		l=i+1,r=n-1;
		cnt=n;
		while(l<=r){
			mid=(l+r)>>1;
			if(a[i]+a[mid]>0){
				r=mid-1;
				cnt=mid;
			}else{
				l=mid+1;
			}
		}
		ans+=(ll)(n-1-cnt+1);
	}
	printf("%lld\n",ans);
	return 0;
}