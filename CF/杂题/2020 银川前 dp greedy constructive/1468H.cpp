// Problem: F - K and Medians
// Contest: Virtual Judge - 5.6-5.13训练，要求题数 >= 3
// URL: https://vjudge.net/contest/437125#problem/F
// Memory Limit: 524 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>k>>m;
		vector<bool> vis(n+1);
		vector<int> l(n+1),r(n+2);
		for(int i=1;i<=m;i++){
			int a;
			cin>>a;
			vis[a]=true;
		}
		if((n-m)%(k-1)==0){
			for(int i=1;i<=n;i++){
				if(!vis[i]) l[i]++;
				l[i]+=l[i-1];
			}
			for(int i=n;i>=1;i--){
				if(!vis[i]) r[i]++;
				r[i]+=r[i+1];
			}
			int cnt=0;
			bool flag=true;
			for(int i=1;i<=n&&flag;i++){
				if(!vis[i]) ;
				else{
					if(l[i]>=k/2&&r[i]>=k/2) flag=false;
				}
			}
			if(!flag||n==m) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}