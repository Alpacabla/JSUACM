/*
link: 
tags: 莫比乌斯函数 O(n)求，基于欧拉筛
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
int pri[max_n];
bool vis[max_n];
int mu[max_n];
int tot;
void init(const int n)
{
	mu[1]=1;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			mu[i]=-1;
			pri[tot++]=i;
		}
		for(int j=0;j<tot&&pri[j]*i<=n;j++){
			vis[pri[j]*i]=true;
			if(i%pri[j]==0){
				mu[i*pri[j]]=0;
				break;
			}else mu[i*pri[j]]=-mu[i];
		}
	}
	return ;
}
int main()
{
	init(1e7);
	return 0;
}
