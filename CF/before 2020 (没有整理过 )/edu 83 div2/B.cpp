#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
int main()
{
	int t;
	int n;
	int i;
	int num[105];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",num+i);
		}
		sort(num,num+n);
		for(i=n-1;i>=0;i--){
			printf("%d ",num[i]);
		}
		printf("\n");
	}

	return 0;
}