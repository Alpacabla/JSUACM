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
		double d,k;
		cin>>d>>k;
		double dd=d*d;
		int lim=d,add=k;
		bool flag=true;
		bool flag1=false;
		int max1=int_inf;
		int aa=-1,bb=-1;
		for(int i=0;i<=lim;i+=add){
			int x=sqrt(d*d-i*i);
			int a=x/add;
			int b=i/add;
			if(a<=25)cout<<a<<" "<<b<<endl;
			//if((a+b)%2==1) flag1=true;
			//if(a==b) flag=false;
			if((a+b)%2==0&&min(a,b)<max1){
				max1=min(a,b);
				flag=false;
			}
			if((a+b)%2==1&&min(a,b)<max1){
				max1=min(a,b);
				flag=true;
			}
			// if((a+b)%2==0&&a>=aa){
			// 	if(a==aa){
			// 		if(b>bb){
			// 			bb=b;
			// 			flag=false;
			// 		}
			// 	}else{
			// 		aa=a;
			// 		bb=b;
			// 		flag=false;
			// 	}
			// }
			// if((a+b)%2==1&&a>=aa){
			// 	if(a==aa){
			// 		if(b>bb){
			// 			bb=b;
			// 			flag=true;
			// 		}
			// 	}else{
			// 		aa=a;
			// 		bb=b;
			// 		flag=true;
			// 	}
			// }
		}
		//cout<<flag1<<endl;
		if(flag) cout<<"Ashish"<<endl;
		else cout<<"Utkarsh"<<endl;
	}
	return 0;
}