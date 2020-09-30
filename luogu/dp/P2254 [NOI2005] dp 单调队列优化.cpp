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
const int max_n=1e5+5;
int dp[205][205][205];
bool book[205][205],vis[205][205];
int sta[205],len[205];
void solve(const int n,const int m,int now)
{
	deque<int>q;
	//cout<<n<<" "<<m<<" "<<now<<endl;
	//memset(vis,false,sizeof(vis));
	if(sta[now]==4){
		for(int i=1;i<=n;i++){
			q.clear();
			//q.push_front(0);
			for(int k=1;k<=m;k++){
				if(vis[i][k]){
					int lim=k+len[now];
					int j;
					for(j=k;j<=lim;j++){
						if(book[i][j]) {q.clear();j++;break;}
						if(vis[i][j]){
							lim=min(m,j+len[now]);
						}
						while(!q.empty()&&abs(j-q.front())>len[now]){
							q.pop_front();
						}
						if(!q.empty()) dp[i][j][now]=max(dp[i][j][now-1],dp[i][q.front()][now-1]+abs(j-q.front()));
						while(!q.empty()&&dp[i][j][now]>dp[i][q.back()][now-1]+abs(j-q.back())){
							q.pop_back();
						}
						q.push_back(j);
					}
					k=j-1;
				}
			}
			
		}
	}else{
		if(sta[now]==3){
			for(int i=1;i<=n;i++){
				q.clear();
				//q.push_front(m+1);
				for(int k=m;k>=1;k--){
					if(vis[i][k]){
						int lim=k-len[now];
						int j;
						for(j=k;j>=lim;j--){
							if(book[i][j]) {q.clear();j--;break;}
							if(vis[i][j]) max(1,lim=j-len[now]);
							while(!q.empty()&&abs(j-q.front())>len[now]){
								q.pop_front();
							}
							if(!q.empty()) dp[i][j][now]=max(dp[i][j][now-1],dp[i][q.front()][now-1]+abs(j-q.front()));
							while(!q.empty()&&dp[i][j][now]>dp[i][q.back()][now-1]+abs(j-q.back())){
								q.pop_back();
							}
							q.push_back(j);
						}
						k=j+1;
					}
				}
			}
		}else{
			if(sta[now]==2){
				for(int j=1;j<=m;j++){
					q.clear();
					//q.push_front(0);
					for(int k=1;k<=n;k++){
						if(vis[k][j]){
							int lim=k+len[now];
							int i;
							for(i=k;i<=lim;i++){
								if(book[i][j]) {q.clear();i++;break;}
								if(vis[i][j]) lim=min(n,i+len[now]);
								while(!q.empty()&&abs(i-q.front())>len[now]){
									q.pop_front();
								}
								if(j==5)cout<<q.front()<<" "<<i<<endl;
								if(!q.empty()) dp[i][j][now]=max(dp[i][j][now-1],dp[q.front()][j][now-1]+abs(i-q.front()));
								while(!q.empty()&&dp[i][j][now]>dp[q.back()][j][now-1]+abs(i-q.back())){
									q.pop_back();
								}
								q.push_back(i);
							}
							k=i-1;
						}
					}
				}
			}else{
				for(int j=1;j<=m;j++){
					q.clear();
					//q.push_front(n+1);
					for(int k=n;k>=1;k--){
						if(vis[k][j]){
							int lim=k-len[now];
							int i;
							for(i=k;i>=lim;i--){
								if(book[i][j]) {q.clear();i--;break;}
								if(vis[i][j]) lim=max(1,i-len[now]);
								while(!q.empty()&&abs(i-q.front())>len[now]){
									q.pop_front();
								}
								if(!q.empty()) dp[i][j][now]=max(dp[i][j][now-1],dp[q.front()][j][now-1]+abs(i-q.front()));
								while(!q.empty()&&dp[i][j][now]>dp[q.back()][j][now-1]+abs(i-q.back())){
									q.pop_back();
								}
								q.push_back(i);
							}
							k=i+1;
						}
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(dp[i][j][now]>=0){
				vis[i][j]=true;
			}else{
				vis[i][j]=false;
				dp[i][j][now]=dp[i][j][now-1];
				if(dp[i][j][now-1]>=0){
					vis[i][j]=true;
				}
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
	int n,m,x,y,k;
	cin>>n>>m>>x>>y>>k;
	for(i=1;i<=n;i++){
		string s;
		cin>>s;
		for(j=0;j<m;j++){
			book[i][j+1]=(s[j]=='x');
		}
	}
	for(i=1;i<=k;i++){
		int l,r;
		cin>>l>>r>>sta[i];
		len[i]=r-l+1;
	}
	memset(dp,-1,sizeof(dp));
	dp[x][y][0]=0;
	vis[x][y]=true;
	for(i=1;i<=k;i++){
		solve(n,m,i);
		cout<<i<<endl;
		for(j=1;j<=n;j++){
			for(int l=1;l<=m;l++){
				cout<<setw(3)<<dp[j][l][i]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
	int max1=-int_inf;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			max1=max(max1,dp[i][j][k]);
		}
	}
	cout<<max1<<endl;
	return 0;
}
