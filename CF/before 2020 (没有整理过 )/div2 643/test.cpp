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
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int a=12;
	char ch='A';
	double f=10.0;
	scanf("%d%c%lf",&a,&ch,&f);
	printf("%d,%c,%.0lf",a,ch,f);


	return 0;
}