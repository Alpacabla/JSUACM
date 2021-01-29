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
ull num[150];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	num[1]=1;
	num[2]=3;
	for(i=3;i<=150;i++){
		for(j=1;j<i;j++){
			num[i]+=num[j];
		}
		num[i]+=i;
	}
	//cout<<num[3]<<endl;
	int t;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		ull ans=0;
		int len=1;
		while(n){
			if(n&1){
				ans+=num[len];
			}
			len++;
			n>>=1;
		}
		cout<<ans<<endl;
	}
	return 0;
}