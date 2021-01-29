#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<queue>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+100;
int head[max_n],to[max_n<<1],nxt[max_n<<1];
int len[max_n],cnt3[max_n];
int in[max_n];
int cnt;
void add(int a,int b)
{
	nxt[++cnt]=head[a];
	head[a]=cnt;
	to[cnt]=b;
	return ;
}
void dfs(int v,int pa,int sta)
{
	int i;
	len[v]=sta;
	for(i=head[v];i;i=nxt[i]){
		if(to[i]!=pa) dfs(to[i],v,!sta);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	cin>>n;
	for(i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		add(a,b);
		add(b,a);
		in[a]++;
		in[b]++;
	}
	for(i=1;i<=n;i++){
		if(in[i]==1){
			cnt3[to[head[i]]]++;
		}
	}
	int maxn=n-1;
	for(i=1;i<=n;i++){
		if(cnt3[i]){
			maxn-=(cnt3[i]-1);
		}
	}
	int min1=1;
	for(i=1;i<=n;i++){
		if(in[i]==1){
			dfs(i,0,0);
			break;
		}
	}
	for(i=1;i<=n;i++){
		if(in[i]==1&&len[i]){
			min1=3;
			break;
		} 
	}
	cout<<min1<<" "<<maxn;
	return 0;
}