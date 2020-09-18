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
		int n,x,m;
		cin>>n>>x>>m;
		int l,r;
		l=r=x;
		int flag=1;
		while(m--){
			int a,b;
			cin>>a>>b;
			if((a<=l&&b>=r)||(a<=r&&a>=l)||(b>=l&&b<=r)){
				l=min(l,a);
				r=max(r,b);
			}
		}
		cout<<r-l+1<<endl;
	}
	return 0;
}