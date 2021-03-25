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
	int t;
	cin>>t;
	while(t--){
		int n;
		map<int,int> mp;
		int max1=-1;
		cin>>n;
		for(int i=0;i<n;i++){
			int a;
			cin>>a;
			max1=max(max1,++mp[a]);
		}
		if(max1<=n-max1){
			//if((n-max1-max1))
			cout<<(n-max1-max1)%2<<endl;
		}else{
			cout<<max1-(n-max1)<<endl;
		}
	}
	return 0;
}