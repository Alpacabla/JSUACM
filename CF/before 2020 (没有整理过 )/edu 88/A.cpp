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
	int t,n,m,k;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		int z=n/k;
		if(m<=z){
			cout<<m<<endl;
		}else{
			int d=m-z;
			if(d%(k-1)==0){
				d/=(k-1);
			}else{
				d/=(k-1);
				d+=1;
			}
			cout<<z-d<<endl;
		}
	}
	return 0;
}