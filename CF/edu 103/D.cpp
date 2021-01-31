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
const int max_n=3e5+10;
int pa[max_n<<1];
int cnt[max_n<<1];
bool vis[max_n][2];
char s[max_n];
int n;
inline int find(int a){
	return pa[a]?pa[a]=find(pa[a]):a;
}
inline void combine(int a,int b){
	a=find(a),b=find(b);
	if(a!=b){
		pa[a]=b;
	}
	return ;
}
void dfs(int a,bool flag,int last)
{
	if(a==0||a==n+2) return ;
	if(last!=-1){
		if(flag) combine(a,last+n+1);
		else combine(a+n+1,last);
	}
	if(vis[a][flag]) return ;
	vis[a][flag]=true;
	if(flag){
		if(s[a-1]=='L') dfs(a-1,!flag,a);
		if(s[a]=='R') dfs(a+1,!flag,a);
	}else{
		if(s[a-1]=='R') dfs(a-1,!flag,a);
		if(s[a]=='L') dfs(a+1,!flag,a);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n+1;i++){
			vis[i][0]=vis[i][1]=false;
		}
		memset(pa,0,sizeof(int)*(2*(n+3)));
		memset(cnt,0,sizeof(int)*(2*(n+3)));
		cin>>(s+1);
		for(int i=1;i<=n+1;i++){
			dfs(i,1,-1);
		}
		for(int i=1;i<=2*(n+1);i++){
			cnt[find(i)]++;
		}
		for(int i=1;i<=n+1;i++){
			cout<<cnt[find(i)]<<" ";
		}
		cout<<endl;
	}
	return 0;
}