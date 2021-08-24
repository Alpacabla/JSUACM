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
		int n;
		cin>>n;
		int k=0;
		int st=1;
		while(k+st<=n){
			k+=st;
			st+=2;
		}
		//st-=2;
		if(k==n) st-=2;
		int r,c;
		if(k==n) k=st;
		else k=n-k;
		if(k>st/2){
			r=(st+1)/2;
			c=r-(k-st/2)+1;
		}else{
			r=k;
			c=(st+1)/2;
		}
		cout<<r<<" "<<c<<endl;
	}
	
	return 0;
}