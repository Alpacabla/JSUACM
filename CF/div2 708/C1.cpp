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
	cin>>n;
	while(n--){
		int a,b;
		cin>>a>>b;
		if(a%2==1){
			cout<<1<<" "<<a/2<<" "<<a/2<<endl;
		}else{
			if(a%4==0){
				cout<<a/2<<" "<<a/4<<" "<<a/4<<endl;
			}else{
				cout<<2<<" "<<a/2-1<<" "<<a/2-1<<endl;
			}
		}
	}
	return 0;
}