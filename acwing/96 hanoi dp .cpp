/*
link: https://www.acwing.com/problem/content/98/
tags: hanoi dp 
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	const int lim=15;
	int hanoi3[lim],hanoi4[lim];
	hanoi3[0]=0;
	for(i=1;i<lim;i++){
		hanoi3[i]=(hanoi3[i-1]<<1)+1;
	}
	memset(hanoi4,0x3f,lim*sizeof(int));
	hanoi4[0]=0;
	for(i=1;i<lim;i++){
		for(j=0;j<i;j++){
			hanoi4[i]=min(hanoi4[i],(hanoi4[j]<<1)+hanoi3[i-j]);
		}
	}
	for(i=1;i<=12;i++){
		cout<<hanoi4[i]<<endl;
	}
	return 0;
}
