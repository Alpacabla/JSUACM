// Problem: B. Lord of the Values
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		//vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			int aa;
			scanf("%d",&aa);
			//a[i]=aa;
		}
		printf("%d\n",3*n);
		for(int i=1;i<=n;i+=2){
			int a=i,b=i+1;
			printf("2 %d %d\n",a,b);
			printf("1 %d %d\n",a,b);
			
			printf("2 %d %d\n",a,b);
			printf("1 %d %d\n",a,b);
			
			printf("2 %d %d\n",a,b);
			printf("1 %d %d\n",a,b);
		}
	}
	return 0;
}