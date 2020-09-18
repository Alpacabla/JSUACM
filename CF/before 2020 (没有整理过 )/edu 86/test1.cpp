#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=40005;
int dp[max_n];
inline void init(int a,int b,int c)
{
	int i;
	for(i=1;i<=c;i++){
		dp[i]+=dp[i-1];
		if(i%a%b!=i%b%a){
			dp[i]++;
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int a,b,n;
		cin>>a>>b>>n;
		int z=a*b;
		init(a,b,z);
		while(n--){
			ll l,r;
			cin>>l>>r;
			l-=1;
			ull ans=dp[z]*(r/z)+dp[r%z]-(dp[z]*(l/z)+dp[l%z]);
			cout<<ans<<" ";
		}
		cout<<endl;
		memset(dp,0,a*b*sizeof(int)+8);
	}
	return 0;
}