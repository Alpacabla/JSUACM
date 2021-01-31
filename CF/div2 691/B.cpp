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
bool vis[50][50];
int cnt;
int sta[4][2]={
	1,0,
	-1,0,
	0,1,
	0,-1,
};
int n;
void dfs(int x,int y,int last,int step)
{
	if(step==n){
		if(!vis[x+25][y+25]){
			vis[x+25][y+25]=1;
			cnt++;
		}
		return ;
	}
	if(last<2||last==-1){
		dfs(x+sta[2][0],y+sta[2][1],2,step+1);
		dfs(x+sta[3][0],y+sta[3][1],3,step+1);
	}
	if(last>=2||last==-1){
		dfs(x+sta[0][0],y+sta[0][1],0,step+1);
		dfs(x+sta[1][0],y+sta[1][1],1,step+1);
	}
	return ;
}
ll dp[1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	// for(int i=1;i<=10;i++){
	// 	memset(vis,false,sizeof(vis));
	// 	n=i;
	// 	dfs(0,0,-1,0);
	// 	cout<<cnt<<endl;
	// 	cnt=0;
	// }
	int n;
	cin>>n;
	dp[1]=dp[2]=4;
	int add1=5,add2=8;
	for(int i=3;i<=n;i++){
		if(i%2==0){
			dp[i]=dp[i-2]+add1;
			add1+=2;
		}else{
			dp[i]=dp[i-2]+add2;
			add2+=4;
		}
	}
	cout<<dp[n]<<endl;
	return 0;
}