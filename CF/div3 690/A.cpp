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
	int t,n,a,b;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> num(n+1),ans(n+1);
		for(int i=0;i<n;i++){
			cin>>num[i];
		}
		for(int i=0,l=0,r=n-1;i<n;i++){
			if(i%2==0){
				ans[i]=num[l++];
			}else{
				ans[i]=num[r--];
			}
		}
		for(int i=0;i<n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}