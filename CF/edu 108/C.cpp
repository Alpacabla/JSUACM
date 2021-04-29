// Problem: C. Berland Regional
// Contest: Codeforces - Educational Codeforces Round 108 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1519/problem/C
// Memory Limit: 256 MB
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
const int max_n=2e5+5;
vector<int> v[max_n];
vector<ll> del[max_n+1];
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
		vector<bool> vis(n+1);
		ll sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			v[i].clear();
			del[i].clear();
			vis[a[i]]=true;
		}
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			v[a[i]].push_back(k);
			sum+=k;
		}
		for(int i=1;i<=n;i++){
			del[i].resize(v[i].size()+1);
			del[i][0]=0;
			sort(v[i].begin(),v[i].end());
			for(int j=1;j<del[i].size();j++){
				del[i][j]=del[i][j-1]+v[i][j-1];
			}
		}
		for(int i=1;i<=n;i++){
			
		}
		list<int> z;
		for(int i=1;i<=n;i++){
			if(vis[i]){
				z.push_back(i);
			}
		}
		vector<ll> out(n+1);
		for(int i=1;i<=n;i++){
			list<int> temp=z;
			z.clear();
			for(auto p:temp){
				if(((int)del[p].size())-1>=i){
					z.push_back(p);
				}else{
					sum-=del[p][del[p].size()-1];
				}
			}
			
			out[i]=sum;
			for(auto p:z){
				out[i]-=del[p][((int)(del[p].size()-1))%i];
			}
		}
		for(int i=1;i<=n;i++){
			cout<<out[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}