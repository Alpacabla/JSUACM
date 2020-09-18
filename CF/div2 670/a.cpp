/*
link: https://codeforces.com/contest/1406/problem/A
tags: easy
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
int vis[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int a,b;
	int n;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(i=0;i<=100;i++) vis[i]=0;
		for(i=0;i<n;i++){
			int num;
			cin>>num;
			vis[num]++;
		}
		int ans=0;
		int z=0;
		for(i=0;i<=104;i++){
			if(!vis[i]){
				ans+=i;
				//cout<<ans<<endl;
				break;
			}
			vis[i]--;
		}
		for(i=0;i<=104;i++){
			if(!vis[i]){
				ans+=i;
				//cout<<ans<<endl;
				break;
			}
			vis[i]--;
		}
		cout<<ans<<endl;
	}
	return 0;
}
