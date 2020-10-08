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
ll bitr[max_n],bitc[max_n];
bool visr[max_n],visc[max_n];
int n;
void update(ll *bit,int ind,ll v)
{
	while(ind<=n){
		bit[ind]+=v;
		ind+=lowbit(ind);
	}
	return ;
}
ll query(ll *bit,int ind)
{
	ll res=0;
	while(ind){
		res+=bit[ind];
		ind-=lowbit(ind);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int q;
	cin>>n>>q;
	//update(bitc,1,n);
	//update(bitr,1,n);
	update(bitr,1,1ll*(n)*(n+1)/2);
	update(bitc,1,1ll*(n)*(n+1)/2);

	// for(i=1;i<=n;i++){
	// 	update(bitr,i,n);
	// 	update(bitc,i,n);
	// }
	// for(i=1;i<=n;i++){
	// 	cout<<query(bitc,i)<<endl;
	// }
	int cntc=0,cntr=0;
	while(q--){
		char ch;
		ll a;
		cin>>ch>>a;
		if(ch=='R'){
			if(visr[a]){
				cout<<0<<endl;
			}else{
				cntr++;
				visr[a]=true;
				cout<<query(bitr,a)+(1ll*(n-cntc)*a)<<endl;
				update(bitc,1,-a);
			}
		}else{
			if(visc[a]){
				cout<<0<<endl;
			}else{
				cntc++;
				visc[a]=true;
				cout<<query(bitc,a)+(1ll*(n-cntr)*a)<<endl;
				update(bitr,1,-a);
			}
		}
	}
	return 0;
}
