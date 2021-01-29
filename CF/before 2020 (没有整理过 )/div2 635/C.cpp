#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
int len[max_n],cnt[max_n],v[max_n];
vector<int>edge[max_n];
void dfs(int v,int pa,int length){
	len[v]=length;
	int i;
	for(i=0;i<edge[v].size();i++){
		if(edge[v][i]!=pa){
			dfs(edge[v][i],v,length+1);
		}
	}
	cnt[pa]+=cnt[v]+1;
	return ;
}
bool cmp(int a,int b){
	return a>b;
}
int main()
{
	int i,j;
	int n,k;
	scanf("%d%d",&n,&k);
	for(i=1;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1,0,0);
	for(i=1;i<=n;i++){
		v[i]=len[i]-cnt[i];
	}
	ll ans=0;
	sort(v+1,v+1+n,cmp);
	//printf("%d\n",v[n]);
	for(i=1;i<=k;i++){
		ans+=(ll)v[i];
	}
	printf("%lld\n",ans);
	return 0;
}