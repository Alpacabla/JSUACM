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
int n,k;
char book[8][8];
int siz[8];
int sta[2][2]={
	1,0,
	0,1,
};
int ans=0;
bool judge(int x,int y){
	if(x<0||x>=n||y<0||y>=n) return true;
	else return false;
}
int count1;
bool vis[8][8];
bool visvis[8];
void dfs(int x,int y,int a,int cnt)
{
	if(a==k){
		ans+=cnt==count1;
		return ;
	}
	for(int i=x;i<n;i++){
		for(int j=i==x?y+1:0;j<n;j++){
			if(book[i][j]=='X') continue;
			for(int o=0;o<k;o++){
				if(!visvis[o]){
					bool flag=true;
					int cntcnt=0;
					for(int v=0;v<siz[o]&&flag;v++){
						if(judge(i+sta[0][0]*v,j+sta[0][1]*v)) flag=false;
						if(book[i+sta[0][0]*v][j+sta[0][1]*v]=='X') flag=false;
						if(vis[i+sta[0][0]*v][j+sta[0][1]*v]) flag=false;
						if(book[i+sta[0][0]*v][j+sta[0][1]*v]=='O') cntcnt++;
					}
					if(flag){
						visvis[o]=true;
						for(int v=0;v<siz[o];v++){
							vis[i+sta[0][0]*v][j+sta[0][1]*v]=true;
						}
						dfs(i,j,a+1,cnt+cntcnt);
						visvis[o]=false;
						for(int v=0;v<siz[o];v++){
							vis[i+sta[0][0]*v][j+sta[0][1]*v]=false;
						}
					}
					if(siz[o]==1) continue;
					flag=true;
					cntcnt=0;
					for(int v=0;v<siz[o]&&flag;v++){
						if(judge(i+sta[1][0]*v,j+sta[1][1]*v)) flag=false;
						if(book[i+sta[1][0]*v][j+sta[1][1]*v]=='X') flag=false;
						if(vis[i+sta[1][0]*v][j+sta[1][1]*v]) flag=false;
						if(book[i+sta[1][0]*v][j+sta[1][1]*v]=='O') cntcnt++;
					}
					if(flag){
						visvis[o]=true;
						for(int v=0;v<siz[o];v++){
							vis[i+sta[1][0]*v][j+sta[1][1]*v]=true;
						}
						dfs(i,j,a+1,cnt+cntcnt);
						visvis[o]=false;
						for(int v=0;v<siz[o];v++){
							vis[i+sta[1][0]*v][j+sta[1][1]*v]=false;
						}
					}
				}
			}
		}
	}
	return ;
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s",book[i]);
	}
	for(int i=0;i<k;i++){
		scanf("%d",siz+i);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(book[i][j]=='O') count1++;
		}
	}
	dfs(0,-1,0,0);
	printf("%d\n",ans);
	return 0;
}