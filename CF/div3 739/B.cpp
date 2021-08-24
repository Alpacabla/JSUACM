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
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int aa,bb;
		if(a>b) swap(a,b);
		aa=a;
		bb=b;
		b-=a-1;
		a=1;
		int d;
		if(c<b){
			d=c+(b-1);
			if(d<b) d=-1;
		}else{
			d=c-(b-1);
			if(d>b) d=-1;
		}
		if(d==bb||d==aa){
			if(d==bb&&c!=aa) d=-1;
			if(d==aa&&c!=bb) d=-1;
		}
		if(b<=aa) d=-1;
		cout<<d<<endl;
	}
	
	return 0;
}