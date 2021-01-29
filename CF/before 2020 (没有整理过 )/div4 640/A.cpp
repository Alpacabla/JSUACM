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
	int n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int>ans;
		int x=10;
		for(i=1;i<=5;i++){
			if(n%x){
				ans.push_back(n%x);
				n-=n%x;
			}
			x*=10;
		}
		cout<<ans.size()<<endl;
		for(i=0;i<ans.size();i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}