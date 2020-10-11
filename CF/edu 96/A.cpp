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
		cin>>n;
		int k=n;
		int a=0,b=0,c;
		c=k/7;
		k%=7;
		int flag=true;
		if(k==1){
			c-=1;
			a=1,b=1;
			if(n<=7){
				flag=false;
			}
		}else{
			if(k==2){
				c-=1;
				a=3,b=0;
				if(n<=7){
					flag=false;
				}
			}else{
				if(k==4){
					a=2,b=1;
					c-=1;
					if(n<=7){
						flag=false;
					}
				}else{
					if(k==6){
						a=2;
					}else{
						if(k==5){
							b=1;
						}else{
							if(k==3){
								a=1;
							}
						}
					}
				}
			}
		}
		if(!flag){
			cout<<-1<<endl;
		}else{
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
	}
	return 0;
}
