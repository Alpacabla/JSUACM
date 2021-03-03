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
int e[1005][1005],v[1005][1005];
int ans[1005],val[1005];
bool vis[1005];
int sum=0;
void prim(int start,int end,int m)
{
	int k;
	int cnt=0;
	ans[start]=0;
	val[start]=0;
	while(1){
		k=-1;
		for(int i=1;i<=m;i++){
			if(ans[i]!=0x3f3f3f3f&&!vis[i]&&(k==-1||ans[i]<ans[k])){
				k=i;
			}
		}
		vis[k]=true;
		if(k==-1||cnt==m){
			break;
		}
		cnt++;
		for(int i=1;i<=m;i++){
			if(ans[i]<ans[k]&&ans[i]+e[i][k]==ans[k]){
				val[k]=min(val[k],val[i]+v[i][k]);	
			}
		}

		for(int i=1;i<=m;i++){
			if(e[k][i]){
				ans[i]=min(ans[i],ans[k]+e[k][i]);
			}
		}
	}
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	while(cin>>m>>n&&m){
		sum=0;
		memset(ans,0x3f,sizeof(int)*(m+2));
		memset(val,0x3f,sizeof(int)*(m+2));
		memset(vis,false,m+2);
		for(int i=1;i<=m;i++){
			memset(e[i],0x3f,sizeof(int)*(m+2));
			memset(v[i],0x3f,sizeof(int)*(m+2));
		}
		for(int i=1;i<=n;i++){
			int a,b,cost,len;
			cin>>a>>b>>len>>cost;
			if(e[a][b]>=len){
				if(e[a][b]>len){
					e[a][b]=e[b][a]=len;
					v[a][b]=v[b][a]=cost;
				}else{
					if(v[a][b]>cost){
						v[a][b]=v[b][a]=cost;
					}
				}
			}
		}
		int s,t;
		cin>>s>>t;
		prim(s,t,m);
		cout<<ans[t]<<" "<<val[t]<<endl;
	}

	return 0;
}