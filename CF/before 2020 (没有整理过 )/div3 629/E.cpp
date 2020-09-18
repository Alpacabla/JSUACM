#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int INF=0x3f3f3f3f;
const int max_n=2e5+5;
vector<int>edge[max_n];
int n,k;
int vis[max_n];
int in[max_n],out[max_n];
int father[max_n];
int now;
void creat_tree(int root)
{
	int i;
	vis[root]=1;
	++now;
	in[root]=now;
	for(i=0;i<edge[root].size();i++){
		int vertex=edge[root][i];
		if(!vis[vertex]){
			father[vertex]=root;
			creat_tree(vertex);
		}
	}
	out[root]=now;
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,k,num;
	int a,b;
	int i,j;
	cin>>n>>k;
	for(i=1;i<n;i++){
		cin>>a>>b;
		edge[b].push_back(a);
		edge[a].push_back(b);
	}
	creat_tree(1);
	while(k--){
		cin>>num;
		int t1=-INF,t2=INF,t3;
		for(i=0;i<num;i++){
			cin>>t3;
			if(t3!=1) t3=father[t3];
			t1=max(t1,in[t3]);
			t2=min(t2,out[t3]);
		}
		if(t1<=t2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}