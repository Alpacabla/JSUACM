#include<stdio.h>
char num[500010];
int yu[400010];
int main()
{
	int q,x;
	int i;
	int n;
	int ans,t;
	scanf("%d %d",&q,&x);
	for(i=0;i<x;i++) yu[i]=i;
	i=0;
	ans=0;
	while(q--){
		scanf("%d",&n);
		t=n%x;
		num[yu[t]]=1;
		if(yu[t]+x<400010){
			yu[t]+=x;
		}
		while(num[i]==1){
			i++;
		}
		printf("%d\n",i);
	}
	return 0;
}
