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
long double C(int a,int b){
	if(a<b) return 0;
	long double res=1.0;
	for(int i=1;i<=b;i++){
		res*=(a-i+1);
	}
	for(int i=1;i<=b;i++){
		res/=(i*1.0);
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	long double ans=0;
	int a,b,c;
	cin>>a>>b>>c;
	int sum=(b+1)*2+c;
	ans=2.0/sum;
	for(i=2;i<=a;i++){
		long double sum1=0;
		long double aa=0;
		//cout<<i<<endl;
		const int lim=i-1;
		for(j=0;j<=lim;j++){
			aa+=C(lim,j);
			sum1=sum1+(C(lim,j)*2.0/(sum-(j*1+((lim-j)*2))));
		} 
		cout<<sum1/aa<<endl;
		ans=ans+sum1/aa;
	}
	//cout<<(2.0/28+4.0/29+2.0/30)/4<<endl;
	cout<<ans/10.0<<endl;
	return 0;
}
