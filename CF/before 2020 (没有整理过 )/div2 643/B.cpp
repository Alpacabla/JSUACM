#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=3e5+5;
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<n;i++){
			cin>>num[i];
		}
		sort(num,num+n);
		int ans=0;
		int last=0;
		for(i=0;i<n;i++){
			if(num[i]==last+1){
				ans++;
				last=0;
			}else{
				last++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}