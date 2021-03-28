/*
link: 
tags: 
*/
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
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	int last=0;
	while(1){
		vector<int> sum(n+1);
		int t=last+1;
		sum[last]=-1;
		for(int i=last+1;i<=n;i++){
			if(a[i]>=m) sum[i]++;
			else sum[i]--;
			sum[i]+=sum[i-1];
			if(sum[i]==0) t=i;
		}
		//cout<<sum[n]<<endl;
		if(sum[n]<0){
			break;
		}
		last=t;
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}