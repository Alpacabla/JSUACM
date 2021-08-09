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
const int max_n=1e6+5;
int book[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		book[a]++;
	}
	ll ans=0;
	for(int i=1;i<=1e6;i++){
        if(book[i]){
            for(int j=i;1ll*i*j<=1e6;j++){
                ans=ans+1ll*book[i]*book[j]*(i==j?1:2)*book[i*j];
            }
        }
	}
	printf("%lld\n",ans);
	return 0;
}