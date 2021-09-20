// Problem: D. The Strongest Build
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1574/problem/D
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const int max_n=2e5+5;
int siz[11];
int a[11][max_n];
set<vector<int> > sets;
set<vector<int> > vis;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>siz[i];
		for(int j=1;j<=siz[i];j++){
			cin>>a[i][j];
		}
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		vector<int> v(n+1);
		for(int j=1;j<=n;j++){
			cin>>v[j];
		}
		sets.insert(v);
	}
	struct node{
		int v;
		vector<int> per;
		bool operator < (const node a) const {
			return v<a.v;
		}
	};
	priority_queue<node> q;
	node aa;
	aa.v=0;
	aa.per.resize(n+1);
	for(int i=1;i<=n;i++) {
		aa.v+=a[i][siz[i]];
		aa.per[i]=(siz[i]);
	}
	q.push(aa);
	vis.insert(aa.per);
	vector<int> ans;
	while(q.size()){
		node ttt=q.top();
		q.pop();
		if(sets.count(ttt.per)){
			
			for(int i=1;i<=n;i++){
				ll v=ttt.v;
				if(ttt.per[i]!=1){
					v-=a[i][ttt.per[i]];
					ttt.per[i]-=1;
					v+=a[i][ttt.per[i]];
					if(!vis.count(ttt.per)){
						vis.insert(ttt.per);
						q.push({v,ttt.per});
					}
					ttt.per[i]+=1;		
				}
			}
		}else{
			ans=ttt.per;
			break;
		}
	}
	for(int i=1;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	return 0;
}