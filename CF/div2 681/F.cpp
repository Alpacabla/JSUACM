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
const int max_n=2e5+5;
int a[max_n],b[max_n],c[max_n];
bool vis[max_n];
const int mod=998244353;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int a1,b1;
		cin>>a1>>b1;
		memset(vis,0,sizeof(int)*(a1+3));
		memset(c,0,sizeof(int)*(a1+3));
		a[0]=max_n-1;
		a[a1+1]=max_n-1;
		c[max_n-1]=max_n-1;
		for(int i=1;i<=a1;i++){
			cin>>a[i];
		}
		for(int i=1;i<=b1;i++){
			cin>>b[i];
			vis[b[i]]=true;
			c[b[i]]=i;
		}
		int ans=1;
		for(int i=1;i<=a1;i++){
			if(vis[a[i]]){
				int cnt=0;
				if(c[a[i-1]]<c[a[i]]){
					cnt++;
				}
				if(c[a[i+1]]<c[a[i]]){
					cnt++;
				}
				ans=ans*cnt%mod;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}