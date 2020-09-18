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
int num[35][35];
int k1[5000],k2[5000];
bool vis[35][35];
int n,m,lim;
void dfs1(int x,int y,int len,int add)
{
	if(vis[x][y]) return ;
	if(x<1||y<1) return ;
	if(x>n||y>m) return ;
	if(len>lim) return ;
	if(num[x][y]) k1[len]++;
	else k2[len]++;
	//cout<<x<<" "<<y<<endl;
	vis[x][y]=true;
	dfs1(x,y+add,len+1,add);
	dfs1(x+add,y,len+1,add);
	return ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		lim=(n+m-2)/2;
		if(((n+m)-2)%2==1) lim+=1;
		memset(k1,0,sizeof(k1));
		memset(k2,0,sizeof(k2));
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				cin>>num[i][j];
				vis[i][j]=false;
			}
		}
		dfs1(1,1,0,1);
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				vis[i][j]=false;
			}
		}
		dfs1(n,m,0,-1);
		int ans=0;
		for(i=0;i<lim;i++){
			ans+=min(k1[i],k2[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}