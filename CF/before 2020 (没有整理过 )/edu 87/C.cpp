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
const double pi=3.1415926535898;
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		n*=2;
		double du=180.0*(n-2)/n/180.0*pi;
		du/=2.0;
		double ans=0.5;
		ans=ans*tan(du)*2;
		printf("%.15lf\n",ans);
	}
	//double x=0.5;
	
	//du/=8;
	//du/=2;
	//x=x*tan(du)*2;
	//cout<<x<<endl;
	//cout<<x*x*3.1415926*16.0/18<<endl;
	return 0;
}