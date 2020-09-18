#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int MOD=998244353;
struct node{
	int num,ind;
	operator < (const node & a)const {
		return num>a.num;
	}
}t[200005];
int book[200005];
int main()
{
	int n,k;
	int i;
	ll sum=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&(t[i].num));
		t[i].ind=i;
	}
	sort(t+1,t+1+n);
	int flag=1;
	int z=INF;
	for(i=1;i<=k;i++){
		sum+=(ll)t[i].num;
		book[t[i].ind]=1;
		z=min(t[i].ind,z);
	}
	/*if(k==1){
		printf("%d %d\n",t[1].num,1);
		return 0;
	}*/
	ll ans=1;
	for(i=z+1;i<=n;i++){
		if(book[i]){
			ans=(ans*(ll)(i-z))%MOD;
			z=i;
		}
	}
	//ans=(ans*(ll)(i-z))%MOD;
	printf("%lld %lld\n",sum,ans);
	return 0;
}