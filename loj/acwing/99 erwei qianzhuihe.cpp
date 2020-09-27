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
int sum[5005][5005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,r;
	cin>>n>>r;
	while(n--){
		int x,y,val;
		cin>>x>>y>>val;
		sum[x+1][y+1]+=val;
	}
	for(int i=1;i<=5001;i++){
		for(int j=1;j<=5001;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+sum[i][j];
		}
	}
	int ans=-1;
	int x=min(5001,r);
	for(int i=x;i<=5001;i++){
		for(int j=x;j<=5001;j++){
			ans=max(ans,sum[i][j]-sum[i-x][j]-sum[i][j-x]+sum[i-x][j-x]);
		}
	}
	cout<<ans<<endl;
	return 0;
}