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
int book[max_n];
int sum[max_n];
int cnt[max_n];
int num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,k;
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>num[i];
		book[num[i]]++;
	}
	sort(num+1,num+1+n,greater<int>());
	sum[0]=0;
	for(i=1;i<=k;i++){
		sum[i]=sum[i-1]+book[i];
	}
	for(i=1;i<=k;i++){
		int t;
		cin>>t;
		if((sum[k]-sum[i-1])%t==0) cnt[i]=(sum[k]-sum[i-1])/t;
		else cnt[i]=(sum[k]-sum[i-1])/t+1;
	}
	int ans=-1;
	for(i=1;i<=k;i++){
		ans=max(ans,cnt[i]);
	}
	vector<int>out[ans+2];
	int now=1;
	for(i=1;i<=n;i++){
		out[(i-1)%ans].push_back(num[now++]);
	}
	cout<<ans<<endl;
	for(i=0;i<ans;i++){
		cout<<out[i].size();
		for(j=0;j<out[i].size();j++){
			cout<<" "<<out[i][j];
		}
		cout<<endl;
	}
	return 0;
}