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
string ans[8];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	ans[4]="3 1 4 2";
	ans[5]="5 3 1 4 2";
	ans[6]="6 3 5 2 4 1";
	ans[7]="7 4 2 6 3 1 5";
	ans[8]="7 5 8 6 3 1 4 2";
	int n;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<4){
			cout<<"-1"<<endl;
		}else{
			if(n<8){
				cout<<ans[n]<<endl;
			}else{
				for(;n>8;n-=4){
					cout<<n-1<<" "<<n-3<<" "<<n<<" "<<n-2<<" ";
				}
				cout<<ans[n]<<endl;
			}
		}
	}
	return 0;
}