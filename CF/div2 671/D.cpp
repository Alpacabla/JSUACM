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
	int i,j;
	int n;
	cin>>n;
	vector<int>num(n);
	for(i=0;i<n;i++){
		cin>>num[i];
	}
	sort(num.begin(),num.end());
	vector<int>ans(n);
	j=0;
	for(i=1;i<=n/2;i++){
		ans[2*i-1]=num[j++];
	}
	for(i=0;i<=n/2;i++){
		ans[2*i]=num[j++];
	}
	int cnt=0;
	for(i=1;i<n-1;i++){
		if(ans[i]<ans[i+1]&&ans[i]<ans[i-1]) cnt++;
	}
	cout<<cnt<<endl;
	for(i=0;i<n;i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}
