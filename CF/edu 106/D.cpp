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
int pri[max_n],tot;
ll zz[10000005];
void init()
{
	int n=1e4;
	for(int i=2;i<=n;i++){
		if(!vis[i]){
			pri[tot++]=i;
		}
		for(int j=0;j<tot&&pri[j]*i<=n;j++){
			vis[pri[j]*i]=true;
			if(i%pri[j]==0) break;
		}
	}
	return ;
}
ll get(int z)
{
	int cnt=0;
	for(int i=0;i<tot&&pri[i]*pri[i]<=z;i++){
		if(z%pri[i]==0){
			cnt++;
			while(z%pri[i]==0){
				z/=pri[i];
			}
		}
	}
	if(z!=1) cnt++;
	return 1<<cnt;
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
		int a,b,c;
		int p1,p2,p3;
		cin>>a>>b>>c;
		if(c==1){

		}
		ll ans=0;
		int x=__gcd(a,b);
		if(c%x!=0){
			cout<<0<<endl;
			continue;
		}
		p1=a/x;
		p2=b/x;
		p3=c/x;
		for(int j=1;j*j<=p3;j++){
			if(p3%j==0){
				int k=p3/j;
				if((k+p2)%p1==0){
					k=(k+p2)/p1;
					ans+=get(k);
				}
				if(p3/j==j){
					continue;
				}
				k=j;
				if((k+p2)%p1==0){
					k=(k+p2)/p1;
					ans+=get(k);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}