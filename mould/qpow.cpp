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
int qpow(int a,int b,const int p)
{
	int res=1%p;
	while(b){
		if(b&1){
			res=1ll*res*a%p;
		}
		b>>=1;
		a=1ll*a*a%p;
	}
	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	int a,b,p;
	cin>>a>>b>>p;
	cout<<qpow(a,b,p)<<endl;
	return 0;
}