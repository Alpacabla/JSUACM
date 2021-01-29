#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define ll long long int
const int INF=0x3f3f3f3f;
int max_n=2e4+5;
int num[max_n];
int k1[40005];
int main()
{
	int n,m,k;
	ll ans=0;
	scanf("%d %d %d",&n,&m,&k);
	int cnt=0;
	int cnt2=0;
	int t;
	int flag=0;
	t=sqrt(k);
	for(i=1;i<=t;i++){
		if(k%i==0){
			k1[cnt2++]=i;
		}
	}
	for(i=0;i<n;i++){
		scanf("%d",&t);
		if(t!=0){
			if(flag) cnt++,flag=1;
			num[cnt]++;
		}else{
			flag=0;
		}
	}
	int z=0;
	for(i=0;i<n;i++){
		scanf("%d",&t);
		if(t!=0){
			z++;
		}else{
			if(z!=0){
				for(j=0;j<cnt;j++){
					
				}
			}
		}
	}

	return 0;
}