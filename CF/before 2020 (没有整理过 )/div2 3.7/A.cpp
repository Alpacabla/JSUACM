#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int main()
{
	int t;
	int n;
	int ans1,ans2;
	int num[105];
	int flag;
	int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		flag=0;
		for(i=1;i<=n;i++){
			scanf("%d",num+i);
		}
		if(n==1&&num[1]%2){
			printf("-1\n");
			continue;
		}
		for(i=1;i<=n;i++){
			if(num[i]%2==0){
				printf("1\n%d\n",i);
				break;
			}else{
				if(flag==0){
					flag=1;
					ans1=i;
				}else{
					ans2=i;
					printf("2\n%d %d\n",ans1,ans2);
					break;
				}
			}
		}
	}

	return 0;
}