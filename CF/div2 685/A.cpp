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
	int n,m;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<0<<endl;
		}else{
			if(n==2){
				cout<<1<<endl;
			}else{
				if(n%2==0||n==3){
					cout<<2<<endl;
				}else{
					cout<<3<<endl;
				}
			}
		}
	}
	return 0;
}