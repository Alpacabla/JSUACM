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
const int max_n=2e5+5;
bool flag[max_n],vis[max_n];
int head[max_n],to[max_n<<1],nxt[max_n<<1],tot;
inline void add(int a,int b)
{
	to[++tot]=b;
	nxt[tot]=head[a];
	head[a]=tot;
	return ;
}
vector<int> res;
void dfs(int a,const bool color)
{
	res.push_back(a);
	vis[a]=true;
	for(int i=head[a];i;i=nxt[i]){
		int &u=to[i];
		if(!vis[u]&&color==flag[u]){
			dfs(u,color);
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(i=1;i<=n;i++){
		int a;
		cin>>a;
		flag[i]=a;
	}
	for(i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	vector<vector<int> > ans;
	int max1=-1;
	ans.clear();
	for(i=1;i<=n;i++){
		if(!vis[i]){
			res.clear();
			dfs(i,flag[i]);
			ans.push_back(res);
			int t=res.size();
			max1=max(max1,t);
		}
	}
	vector<int> out;
	out.clear();
	for(i=0;i<ans.size();i++){
		if(ans[i].size()==max1){
			for(j=0;j<ans[i].size();j++){
				out.push_back(ans[i][j]);
			}
		}
	}
	sort(out.begin(),out.end());
	cout<<out.size()<<endl;
	for(i=0;i<out.size();i++){
		cout<<(i==0?"":" ")<<out[i];
	}
	cout<<endl;
	return 0;
}
