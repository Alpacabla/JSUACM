/*
link: 
tags: 
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			int v;
			cin>>v;
			a[v]=i;
		}
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			vector<int> vis(n+2);
			int cnt=0;
			for(int j=i;j<=n;j++){
				vis[a[j]]=1;
				if(!vis[a[j]-1]&&!vis[a[j]+1]){
					cnt++;
				}else{
					if(vis[a[j]-1]&&vis[a[j]+1]){
						cnt--;
					}
				}
				if(cnt<=2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}