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
vector<int> edge[1050];
bool vis[1050];
int v[1050];
void dfs(int a,int len)
{
	if(vis[a]) return ;
	vis[a]=true;
	v[a]=len;
	int i;
	for(i=0;i<edge[a].size();i++){
		dfs(edge[a][i],len+1);
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,x;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>x;
		memset(v,0,n*4+20);
		memset(vis,false,n+5);
		for(i=1;i<=n;i++){
			edge[i].clear();
		}
		for(i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		if(edge[x].size()==1||n==1){
			cout<<"Ayush"<<endl;
			//cout<<"yes"<<endl;
		}else{
			//dfs(x,0);
			//int cnt=0;
			// for(i=1;i<=n;i++){
			// 	if(edge[i].size()==1){
			// 		cnt+=v[i];
			// 	}
			// }
			//cout<<cnt<<endl;
			if(n%2==1){
				cout<<"Ashish"<<endl;
			}else{
				cout<<"Ayush"<<endl;
			}
		}
	}
	return 0;
}