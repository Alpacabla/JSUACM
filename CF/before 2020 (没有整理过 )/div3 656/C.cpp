#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
int num[max_n];
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
		for(i=1;i<=n;i++){
			cin>>num[i];
		}
		int temp=num[n];
		for(i=n;i>=1;i--){
			if(num[i]>=temp){
				temp=num[i];
			}else{
				break;
			}
		}
		for(;i>=1;i--){
			if(num[i]<=temp){
				temp=num[i];
			}else{
				break;
			}
		}
		cout<<i<<endl;
	}
	return 0;
}