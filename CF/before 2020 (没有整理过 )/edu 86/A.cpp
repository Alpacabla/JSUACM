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
	int t,n,m;
	cin>>t;
	while(t--){
		ll x,y,a,b;
		cin>>x>>y;
		cin>>a>>b;
		if(a<=b/2){
			cout<<a*(abs(x)+abs(y))<<endl;
		}else{
			if(x==0||y==0){
				cout<<a*(abs(x)+abs(y))<<endl;
			}else{
				if((x<0&&y<0)||(x>0&&y>0)){
					cout<<b*min(abs(x),abs(y))+a*(max(abs(x),abs(y))-min(abs(x),abs(y)))<<endl;
				}else{
					cout<<a*(abs(x)+abs(y))<<endl;
				}
			}
		}
		
	}
	return 0;
}