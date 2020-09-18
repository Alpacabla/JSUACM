#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[1000010],n;
int b[1000010];
void q_sort(int l,int r)
{
	if(l>=r)return ;
	else
	{
		int i=l,j=r,mark=a[(l+r)/2];
		while(i<j)
		{
			while(a[i]<mark)
			{
				i++;
				if(i>=j)break;
			}
			if(i>=j) break;
			while(a[j]>mark)
			{
				j--;
				if(j<=i)break;
			}
			if(i<j)
			{
				int t;
				t=a[i];
				a[i]=a[j];
				a[j]=t;
				i++;
				j--;
			}
		}
		q_sort(l,j);
		q_sort(j+1,r);
	}
}
int main()
{
	cin >> n;
	int c[100];
	int i;
	while(1){
		for( i=0;i<n;i++){
			c[i]=b[i]=a[i]=rand();
		}
		q_sort(0,n-1);
		sort(b,b+n);
		for( i=0;i<n;i++){
			if(b[i]!=a[i]){
				break;
			}
		}
		if(i!=n){
			for(i=0;i<n;i++){
				printf("%d ",a[i]);
			}
			printf("\n");
			for(i=0;i<n;i++){
				printf("%d ",c[i]);
			}
			scanf("%d",&i);
		}
	}
	
	return 0;
}
