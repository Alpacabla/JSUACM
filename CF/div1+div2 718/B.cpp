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
int a[105][105];
struct node{
	int v,ind;
	bool operator < (const node a) const {
		return v<a.v;
	}
};
vector<int> ans[105];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<node> num(n*m);
		int tot=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				num[tot++]=(node){a[i][j],i};
			}
		}
		for(int i=1;i<=n;i++){
			sort(a[i]+1,a[i]+1+m);
		}
		sort(num.begin(),num.end());
		for(int i=0;i<m;i++){
			ans[i].clear();
		}
		vector<int> s(n+1,1),e(n+1,m);
		for(int i=0;i<m;i++){
			int &now=num[i].ind;
			for(int j=1;j<=n;j++){
				if(j==now){
					ans[i].push_back(a[j][s[j]++]);
				}else{
					ans[i].push_back(a[j][e[j]--]); 
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<ans[j][i]<<" ";
			}
			cout<<endl;
		}
	}



	return 0;
}
