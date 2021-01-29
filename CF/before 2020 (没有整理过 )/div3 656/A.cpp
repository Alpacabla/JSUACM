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
	int x,y,z;
	int n;
	cin>>n;
	while(n--){
		int a[3];
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(a[2]==a[1]){
			cout<<"YES"<<endl;
			if(a[0]==a[1]){
				cout<<a[1]<<" "<<a[2]<<" "<<a[0]<<endl;
			}else{
				cout<<a[1]<<" "<<a[0]<<" "<<a[0]<<endl;
			}
		}else{
			cout<<"NO"<<endl;
		}
	}
	

	return 0;
}