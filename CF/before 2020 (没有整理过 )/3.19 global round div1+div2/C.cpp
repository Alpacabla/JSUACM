#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
char s[100005];
int main()
{
	int n;
	int t;
	int i;
	cin>>t;
	int k=0;
	int max1=-INF;
	int num;
	while(t--){
		scanf("%d",&num);
		max1=max(max1,k);
		k=max1+num;
		printf("%d ",max1+num);
	}
	return 0;
}