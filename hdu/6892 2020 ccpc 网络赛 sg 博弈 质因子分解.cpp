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
bool vis[max_n];
int pri[max_n/10];
int tot;
void init()
{
	const int lim=sqrt(1e9+5);
	for(int i=2;i<=lim;i++){
		if(!vis[i]){
			pri[tot++]=i;
		}
		for(int j=0;j<tot&&pri[j]*i<=lim;j++){
			vis[pri[j]*i]=true;
			if(i%pri[j]==0) break;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	init();
	cin>>t;
	while(t--){
		int n;
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int a;
			int cnt=0;
			cin>>a;
			if(a%2==0){
				while(a%2==0){
					a/=2;
				}
				cnt=1;
			}
			for(int j=1;j<tot&&pri[j]*pri[j]<=a;j++){
				while(a%pri[j]==0){
					a/=pri[j];
					cnt++;
				}
			}
			if(a!=1) cnt++;
			ans^=cnt;
		}
		if(ans) cout<<"W"<<endl;
		else cout<<"L"<<endl;
	}
	return 0;
}