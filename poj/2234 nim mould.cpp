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
	int n;
	while(cin>>n){
		int ans=0;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			ans^=a;
		}
		if(ans) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	
	return 0;
}