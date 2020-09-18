#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int INF=0x3f3f3f3f;
const int max_n=5e5+5;
int pri[max_n/4];
bool vis[max_n];
int num[max_n];
int main()
{
	int cnt,cnt1;
	int i,j;
	int n;
	cin>>n;
	pri[0]=1;
	cnt=0;
	cnt1=0;
	int lim=n/2;
	for(i=2;i<=lim;i++){
		if(!vis[i]){
			pri[cnt++]=i;
		}
		for(j=0;j<cnt&&pri[j]*i<=n;j++){
			vis[pri[j]*i]=1;
			num[cnt1++]=i;
			if(i%pri[j]==0) break;
		}
	}
	for(i=0;i<cnt;i++){
		printf("1 ");
	}
	for(i=0;i<cnt1;i++){
		printf("%d ",num[i]);
	}
	return 0;
}