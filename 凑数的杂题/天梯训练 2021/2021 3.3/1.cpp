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
	double a,b,c,d;
	cin>>a>>b>>c>>d;
	if(d<a){
		cout<<"BW-Solid";
	}else{
		if(d>a) cout<<"R-Hollow";
		else cout<<"R-Cross";
	}
	if(c<a&&c<d&&b>a&&b>d) cout<<" with Lower Shadow and Upper Shadow";
	else if(c<a&&c<d) cout<<" with Lower Shadow";
	else if(b>a&&b>d) cout<<" with Upper Shadow";
	cout<<endl;
	return 0;
}