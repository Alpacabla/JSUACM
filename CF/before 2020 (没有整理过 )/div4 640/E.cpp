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
int vis[8010];
int num[8010];
int main()
{
	register int i,j;
	int t;
	int n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		memset(vis,0,(n+3)*sizeof(int));
		for(i=1;i<=n;i++){
			scanf("%d",num+i);
			vis[num[i]]++;
		}
		int ans=0;
		for(i=1;i<=n;i++){
			register int sum=num[i];
			//cout<<"ok"<<endl;
			for(j=i+1;j<=n;j++){
				sum+=num[j];
				//cout<<sum<<endl;
				if(sum>n) break;
				if(vis[sum]){
					ans+=vis[sum];
					vis[sum]=0;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}