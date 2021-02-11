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
struct node{
	int a,b;
	bool operator < (const node c) const {
		return a<c.a;
	}
}nodes[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int a,b,n;
		cin>>a>>b>>n;
		for(int i=0;i<n;i++){
			cin>>nodes[i].a;
		}
		for(int i=0;i<n;i++){
			cin>>nodes[i].b;
		}
		sort(nodes,nodes+n);
		bool flag=true;
		ll sum=0;
		for(int i=0;i<n;i++){
			ll k=nodes[i].b/a;
			if(nodes[i].b%a!=0) k++;
			sum+=k*nodes[i].a;
		}
		sum-=nodes[n-1].a;
		if(sum<1ll*b){
			cout<<"YES"<<endl;
		}else cout<<"NO"<<endl;
	}
	return 0;
}