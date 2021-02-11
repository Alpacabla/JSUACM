/*
link: 
tags: 
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int num[max_n];
int n;
inline bool check(int a)
{
	return num[a]&&a<=n&&a>=1&&num[a]<num[a+1]&&num[a]<num[a-1];
}
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int i,j;
	scanf("%d",&n);
	printf("? 1\n");
	fflush(stdout);
	scanf("%d",num+1);
	
	int res=-1;
	int l,r,mid;
	num[n+1]=num[0]=int_inf;
	l=1;
	r=n;
	while(1){
		if(check(l)){
			res=l;
			break;
		}
		mid=(l+r)>>1;
		if(!num[mid]){
			printf("? %d\n",mid);
			fflush(stdout);
			scanf("%d",num+mid);
		}
		if(!num[mid+1]){
			printf("? %d\n",mid+1);
			fflush(stdout);
			scanf("%d",num+mid+1);
		}
		if(check(mid)){
			res=mid;
			break;
		}
		if(check(mid+1)){
			res=mid+1;
			break;
		}
		if(check(mid-1)){
			res=mid-1;
			break;
		}
		if(num[mid+1]>num[mid]){
			r=mid;
		}else{
			l=mid+1;
		}
	}
	printf("! %d\n",res);
	fflush(stdout);
	return 0;
}