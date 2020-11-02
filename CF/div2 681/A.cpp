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
bool vis1[500];
void init(const int n)
{
	for(int i=2;i<=n;i++){
		int j;
		for(j=2;j<i;j++){
			if(i%j==0) break;
		}
		if(j==i) vis1[i]=true;
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t,n,m;
	init(500);
	cin>>t;
	while(t--){
		cin>>n;
		int k=0;
		for(int j=4*n;j>=2&&k<n;j-=2){
			cout<<j<<" ";
			k++;
		}
		cout<<endl;
	}
	return 0;
}