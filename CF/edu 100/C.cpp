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
		int n;
		cin>>n;
		vector<ll> a(n+2),b(n+2);
		ll t=0,last=0,times=0,end=0;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
		}
		a[n+1]=ll_inf;
		for(int i=1;i<=n;i++){
			// cout<<"i"<<i<<endl;
			// cout<<abs(b[i]-last)<<endl;
			bool flag=true;
			if(((b[i]<=t&&b[i]>=last)||(b[i]<=last&&b[i]>=t))&&times+abs(b[i]-last)>=a[i]&&times+abs(b[i]-last)<=a[i+1]){
				cnt++;
				flag=false;
			}
			if(a[i]>=end){
				last=t;
				t=b[i];
				times=a[i];
				end=a[i]+abs(b[i]-last);
				if(end<=a[i+1]){
					if(flag) cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}