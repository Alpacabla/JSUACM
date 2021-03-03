/*
link: 
tags: 
*/
#include<algorithm>
#include<iostream>
#include<vector>
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
		int s;
		int ans=int_inf;
		cin>>n>>s;
		vector<int> sum(n+1);
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			if(a>=s){
				ans=1;
			}
			sum[i]=sum[i-1]+a;
			if(sum[i]>=s){
				int k=int(lower_bound(sum.begin()+1,sum.begin()+i,sum[i]-s)-sum.begin());
				ans=min(ans,i-k+1);
			}
		}
		if(ans==int_inf) cout<<0<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}