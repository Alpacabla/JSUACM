#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int max_n=1e2;
int num[max_n];
int main()
{
	int i,j;
	scanf("%d",&i);
	for(j=0;j<i;j++){
		int a,b,t;
		scanf("%d %d",&a,&b);
		if(a==b){
			printf("0\n");
			continue;
		}
		if(a>b){
			t=a-b;
			if(t%2==0){
				printf("1\n");
			}else{
				printf("2\n");
			}
		}else{
			t=b-a;
			if(t%2==0){
				printf("2\n");
			}else{
				printf("1\n");
			}
		}
	}
	return 0;
}