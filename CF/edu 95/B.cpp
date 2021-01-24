/*
link: https://codeforces.com/contest/1418/problem/B
tags: greedy
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
int num[105];
bool vis[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(i=0;i<n;i++){
			cin>>num[i];
		}
		for(i=0;i<n;i++){
			int k;
			cin>>k;
			vis[i]=k;
		}
		vector<int>a;
		for(i=0;i<n;i++){
			if(!vis[i]) a.push_back(num[i]);
		}
		sort(a.begin(),a.end(),greater<int>());
		for(i=0,j=0;i<n;i++){
			if(!vis[i]) num[i]=a[j++];
		}
		for(i=0;i<n;i++){
			cout<<num[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
