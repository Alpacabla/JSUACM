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
#define endl '\n'
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		double a,b,c;
		int n;
		scanf("%d%lf%lf%lf",&n,&a,&b,&c);
		double k=(a+b)/2.0;
		if(n==2){
			if(k!=c||a<b) puts("no");
			else puts("yes");
		}else{
			if(a<b) puts("no");
			else{
				double l,r;
				l=((n-1)*b+a)/n;
				r=((n-1)*a+b)/n;
				if(c<=r&&c>=l) puts("yes");
				else puts("no");
			}
		}
	}
	return 0;
}