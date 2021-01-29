#include<stdio.h>
#include<string.h>
int main()
{
	int max;
	int a,b,c,n;
	int t;
	int cnt;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d",&a,&b,&c,&n);
		max=(a>b?a:b);
		max=(c>max?c:max);
		cnt=max-a;
		cnt+=max-b;
		cnt+=max-c;
		n-=cnt;
		if(n>=0&&n%3==0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
