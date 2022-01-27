// Problem: C. Not Assigning
// Contest: Codeforces - Codeforces Round #766 (Div. 2)
// URL: https://codeforces.com/contest/1627/problem/C
// Memory Limit: 256 MB
// Time Limit: 1500 ms
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
vector<int> e[max_n],ind[max_n];
void dfs(vector<int> &ans,int a,int fa,int k)
{
	for(int i=0;i<e[a].size();i++){
		int &u=e[a][i];
		if(u!=fa){
			if(k%2==0){
				ans[ind[a][i]]=2;
			}else{
				ans[ind[a][i]]=5;
			}
			dfs(ans,u,a,k+1);
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			e[i].resize(0);
			ind[i].resize(0);
		}
		vector<int> cnt(n+1);
		vector<int> a(n+1),b(n+1);
		for(int i=1;i<n;i++){
			int ee,v;
			cin>>ee>>v;
			cnt[ee]++;
			cnt[v]++;
			a[i]=ee;
			b[i]=v;
			e[ee].push_back(v);
			e[v].push_back(ee);
			ind[ee].push_back(i);
			ind[v].push_back(i);
		}
		
			if(n==2){
				cout<<2<<endl;
			}else{
				if(n==3){
					cout<<2<<" "<<5<<endl;
				}else{
					bool flag=true;
					for(int i=1;i<=n;i++){
						if(cnt[i]>=3){
							flag=false;
						}
					}
					if(!flag){
						cout<<-1<<endl;
					}else{
						vector<int> ans(n);
						int root=1;
						for(int i=1;i<n;i++){
							if(cnt[i]==1){
								root=i;
							}
						}
						dfs(ans,root,-1,0);
						for(int i=1;i<n;i++){
							cout<<ans[i]<<" ";
						}
						cout<<endl;
					}
				}
			}
	}
	
	
	return 0;
}