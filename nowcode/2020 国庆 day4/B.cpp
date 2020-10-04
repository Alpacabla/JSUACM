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
const int max_n=5e3+5;
vector<int> d[max_n],dp[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	vector<int> num(n);
	for(i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num.begin(),num.end());
	int ans=1;
	for(i=0;i<n;i++){
		for(j=i-1;j>=0;j--){
			d[i].push_back(num[i]-num[j]);
			//cout<<num[i]-num[j]<<" ";
			//dp[j].push_back(1);
			int v=1;
			int k=lower_bound(d[j].begin(),d[j].end(),num[i]-num[j])-d[j].begin();
			if(k<d[j].size()&&d[j][k]==num[i]-num[j]){
				//cout<<1<<endl;
				v+=dp[j][k];
			}
			ans=max(ans,v);
			dp[i].push_back(v);
		}
	}
	cout<<ans+1<<endl;
	return 0;
}
