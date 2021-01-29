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
	ull n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		m--;
		while(m--){
			ull t=n;
			int min1=10,max1=-1;
			while(t){
				int a=t%10;
				//cout<<a<<endl;
				min1=min(a,min1);
				max1=max(a,max1);
				t/=10;
			}
			if(min1==0){
				break;
			}else{
				n+=min1*max1;
			}
		}
		cout<<n<<endl;
	}

	return 0;
}