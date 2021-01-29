#include<stdio.h>
#include<math.h>
int main()
{
	int cnt;
	int i;
	int ans[3];
	int t;
	int num;
	int max;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&num);
		cnt=0;
		i=2;
		max=sqrt(num)+1;
		while(cnt<2){
			for(;i<=max;i++){
				if(num%i==0){
					break;
				}
			}
			if(num%i==0){
				ans[cnt++]=i;
				num/=i;
				i++;
			}else{
				break;
			}
		}
		if(cnt==2&&ans[1]!=num&&num>=2&&num!=ans[0]){
			printf("YES\n");
			printf("%d %d %d\n",ans[0],ans[1],num);
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}
