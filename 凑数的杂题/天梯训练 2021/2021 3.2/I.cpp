/*
link: 
tags: 
*/
#include<iostream>
#include<string.h>
#include<algorithm>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int e[105][105];
int ans[105];
bool vis[105];
int sum=0;
bool prim(int m)
{
	int k;
	int cnt=0;
	ans[1]=0;
	while(1){
		k=-1;
		for(int i=1;i<=m;i++){
			if(ans[i]!=0x3f3f3f3f&&!vis[i]&&(k==-1||ans[i]<ans[k])){
				k=i;
			}
		}
		vis[k]=true;
		//cout<<k<<endl;
		if(k==-1||cnt==m){
			break;
		}
		cnt++;
		int min1=int_inf;
		for(int i=1;i<=m;i++){
			if(ans[i]<ans[k]&&ans[i]+e[i][k]==ans[k]){
				min1=min(min1,e[i][k]);
			}
		}
		if(k!=1) sum+=min1;
		for(int i=1;i<=m;i++){
			if(e[k][i]){
				ans[i]=min(ans[i],ans[k]+e[k][i]);
			}
		}
	}
	return cnt==m;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	while(cin>>n>>m&&n){
		sum=0;
		memset(ans,0x3f,sizeof(int)*(m+2));
		memset(vis,false,m+2);
		for(int i=1;i<=m;i++){
			memset(e[i],0x3f,sizeof(int)*(m+2));
		}
		for(int i=1;i<=n;i++){
			int a,b,v;
			cin>>a>>b>>v;
			if(!e[a][b]) e[a][b]=v;
			else e[a][b]=min(e[a][b],v);
			if(!e[b][a]) e[b][a]=v;
			else e[b][a]=min(e[b][a],v);
		}
		if(!prim(m)) cout<<"?"<<endl;
		else cout<<sum<<endl;
	}

	return 0;
}