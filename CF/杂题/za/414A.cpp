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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,k;
	cin>>n>>k;
	if(n==1){
		if(k==0) cout<<1<<endl;
		else cout<<-1<<endl;
		return 0;
	}
	if(n/2>k){
		cout<<-1<<endl;
	}else{
		int lim=n/2-1;
		int start=k-n/2+1;
		cout<<start<<" "<<start*2;
		int now=start*2+1;
		for(int i=1;i<=lim;i++){
			cout<<" "<<now<<" "<<now+1;
			now+=2;
		}
		if(n%2==1){
			cout<<" "<<now;
		}
		cout<<endl;
	}
	return 0;
}