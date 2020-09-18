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
	int n,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		int lim=sqrt(n);
		int max1=-1;
		for(i=1;i<=lim;i++){
			if(n%i==0){
				int a=n/i;
				if(a<=k){
					max1=max(a,max1);
				}
				a=i;
				if(a<=k){
					max1=max(a,max1);
				}
			}
		}
		cout<<n/max1<<endl;
	}
	return 0;
}