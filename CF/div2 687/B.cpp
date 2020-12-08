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
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=int_inf;
		for(int i=1;i<=100;i++){
			int j=1;
			int cnt=0;
			while(j<=n){
				if(a[j]!=i){
					j+=m;
					cnt++;
				}else j++;
			}
			ans=min(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}