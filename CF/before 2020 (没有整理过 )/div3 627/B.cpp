#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
int num[5005];
int main()
{
	int t;
	int i,j;
	int n;
	
	scanf("%d",&t);
	while(t--){
		memset(num,0,sizeof(num));
		scanf("%d",&n);
		int k;int flag=0;
		int last=-1;
		for(i=0;i<n;i++){
			scanf("%d",&k);
			num[k]++;
			if((num[k]>=2&&last!=k)||num[k]>=3){
				flag=1;
			}
			last=k;
		}
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}