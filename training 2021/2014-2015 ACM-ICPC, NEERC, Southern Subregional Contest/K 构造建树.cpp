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
int a[2005][2005];
bool vis[2005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(vis,0,sizeof(bool)*(n+1));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
		vector<int> ans1,ans2;
		vis[1]=true;
		for(int i=2;i<=n;i++){
			int k=a[1][i];
			for(int j=2;j<=n;j++){
				if(vis[a[k][j]]){
					vis[k]=true;
					ans1.push_back(k);
					ans2.push_back(a[k][j]);
					break;
				}
			}
		}
		for(int i=0;i<ans1.size();i++){
			cout<<ans1[i]<<" "<<ans2[i]<<endl;
		}
		cout<<endl;
	}
	return 0;
}