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
int a[105];
int ans[105];
void dfs(int ind,int dep,int l,int r)
{
	ans[ind]=dep;
	int k=0;
	for(int i=l;i<ind;i++){
		if(a[k]<a[i]){
			k=i;
		}
	}
	if(k!=0) dfs(k,dep+1,l,ind-1);
	k=0;
	for(int i=ind+1;i<=r;i++){
		if(a[k]<a[i]){
			k=i;
		}
	}
	if(k!=0) dfs(k,dep+1,ind+1,r);
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
		int n;
		cin>>n;
		int k;
		a[0]=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==n) k=i;
		}
		dfs(k,0,1,n);
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}