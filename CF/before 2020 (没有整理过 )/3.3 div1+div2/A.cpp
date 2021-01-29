#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int num1[1005],num2[1005];
int main()
{
	int n;
	int i,j;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",num1+i);
		}
		for(i=0;i<n;i++){
			scanf("%d",num2+i);
		}
		sort(num1,num1+n);
		sort(num2,num2+n);
		for(i=0;i<n;i++){
			printf("%d ",num1[i]);
		}
		printf("\n");
		for(i=0;i<n;i++){
			printf("%d ",num2[i]);
		}
		printf("\n");
	}
	return 0;
}