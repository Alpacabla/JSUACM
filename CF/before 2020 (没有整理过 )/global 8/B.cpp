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
ll dp[10];
ll k;
string s;
bool judge(int mid)
{
	int i,j;
	const string ts="codeforces";
	s="";
	int x=mid/10;
	int cnt1[10]={0};
	for(i=0;i<=9;i++){
		cnt1[i]=x;
	}
	for(i=0;i<mid%10;i++){
		cnt1[i]+=1;
	}
	for(i=0;i<=9;i++){
		for(j=0;j<cnt1[i];j++){
			s+=ts[i];
		}
	}
	// for(i=0;i+10<=mid;i+=10){
	// 	s+=ts;
	// }
	// for(i=10-(mid%10);i<=9;i++){
	// 	s+=ts[i];
	// }
	//cout<<s<<endl;
	memset(dp,0,sizeof(ll)*10);
	ll cnt=0;
	for(i=0;i<mid;i++){
		for(j=0;j<=9;j++){
			if(s[i]==ts[j]){
				if(j==0) dp[j]++;
				else dp[j]+=dp[j-1];
				// for(l=0;l<=9;l++){
				// 	if(ts[l]==s[i]){
				// 		if(l==0) dp[0]++;
				// 		else dp[l]+=dp[l-1];
				// 	}
				// }
			}
		}
	}
	//cout<<dp[9]<<endl;
	return dp[9]>=k;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int a,b;
	cin>>k;
	string ans;
	ll l=10,r=500;
	while(l<=r){
		ll mid=(l+r)>>1;
		if(judge(mid)){
			ans=s;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
}