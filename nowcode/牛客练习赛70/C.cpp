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
const int max_n=1e7+5;
const int lim=1e7;
int pri[max_n];
bool vis[max_n];
int um[max_n];
int cnt[max_n];
int tot;
void init(const int n)
{
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			um[i]=-1;
			pri[tot++]=i;
		}
		for(int j=0;j<tot&&pri[j]*i<=n;j++){
			vis[pri[j]*i]=true;
			if(i%pri[j]==0){
				um[i*pri[j]]=0;
				break;
			}else um[i*pri[j]]=-um[i];
		}
	}
	um[1]=1;
	int l=1;
	for(int i=2;i<=n;i++){
		if(um[i]==-1){
			cnt[i]=i-l;
		}else{
			l=i;
		}
	}
	l=n;
	for(int i=n-1;i>=1;i--){
		if(um[i]==1){
			cnt[i]=l-i;
		}else{
			l=i;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	init(1e7);
	cin>>n;
	while(n--){
		ll a,b;
		cin>>a>>b;
		if(!um[a]){
			cout<<a<<endl;
		}else{
			if(b<=cnt[a]){
				if(um[a]==1) cout<<a+b<<endl;
				else cout<<a-b<<endl;
			}else{
				b-=cnt[a];
				if(um[a]==1) a+=cnt[a];
				else a-=cnt[a];
				if(!um[a]){
					cout<<a<<endl;
					continue;
				}
				b%=2;
				if(b==0){
					cout<<a<<endl;
				}else{
					cout<<a+um[a]<<endl;
				}
			}
		}
	}
	return 0;
}
