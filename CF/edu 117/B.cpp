// Problem: B. Special Permutation
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1612/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
		int n,a,b;
		cin>>n>>a>>b;
		vector<int> v(n+1);
		vector<int> vis(n+1);
		int max1=n;
		v[1]=a;
		
		for(int i=2;i<=n/2;i++){
			while(max1==b||max1==a) max1--;
			//vis[max1]=true;
			
			v[i]=max1;
			max1--;
		}
		v[n]=b;
		
		for(int i=n/2+1;i<n;i++){
			while(max1==a||max1==b) max1--;
			v[i]=max1;
			max1--;
		}
		bool flag=true;
		for(int i=1;i<=n/2;i++){
			if(v[i]<=0) flag=false;
			if(v[i]<a) flag=false;
		}
		for(int i=n/2+1;i<=n;i++){
			if(v[i]<=0) flag=false;
			if(v[i]>b) flag=false;
		}
		// for(int i=1;i<=n;i++){
				// cout<<v[i]<<" ";
			// }
			// cout<<endl;
		if(!flag) cout<<-1<<endl;
		else{
			for(int i=1;i<=n;i++){
				cout<<v[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}