#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int max_n=4e5+5;
int n;
int num[max_n];
int mod[max_n];
ll pow2[32];
bool judge(int k)
{
	int i;
	ll cnt=0;
	for(i=0;i<n;i++){
		mod[i]=num[i]%pow2[k+1];
	}
	sort(mod,mod+n);
	for(i=0;i<n;i++){
		cnt+=lower_bound(mod+i+1,mod+n,pow2[k+1]-mod[i])-lower_bound(mod+i+1,mod+n,pow2[k]-mod[i]);
		cnt+=lower_bound(mod+i+1,mod+n,pow2[k+1]+pow2[k]-mod[i])-lower_bound(mod+i+1,mod+n,pow2[k+2]-mod[i]);	
	}
	return (bool)(cnt%2);
}
int main()
{
	int ans=0;
	ll x=1;
	int max1=0,t;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",num+i);
		if(num[i]>max1) max1=num[i];	
	}
	for(i=0;i<32;i++){
		pow2[i]=x;
		if(max1>=x){
			t=i+1;
		}
		x<<=1;
	}
	for(i=0;i<=t;i++){
		if(judge(i)) ans+=(int)pow2[i];
	}
	printf("%d\n",ans);
	return 0;
}