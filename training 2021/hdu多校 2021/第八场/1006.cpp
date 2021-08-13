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
int a[max_n];
const int max_m=1e7+5;
bool vis[max_m];
int pri[max_n],tot,k;
int cnt[max_m];
void init(int n)
{
	cnt[1]=0;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			pri[tot++]=i;
			cnt[i]=1;
		}
		for(int j=0;j<tot&&i*pri[j]<=n;j++){
			vis[i*pri[j]]=true;
			cnt[i*pri[j]]=cnt[i]+1;
			if(i%pri[j]==0) break;
		}
	}
	return ;
}
int main()
{
	int t;
	init(1e7);
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",a+i);
		}
		int g=0;
		for(int i=1;i<=n;i++){
			g^=cnt[a[i]];
		}
		if(g==0) printf("Bob\n");
		else printf("Alice\n");
	}
	return 0;
}