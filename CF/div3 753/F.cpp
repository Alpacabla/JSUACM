// Problem: F. Robot on the Board 2
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int sta[200][2];
int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	sta['R'][0]=0;
	sta['R'][1]=1;
	sta['L'][0]=0;
	sta['L'][1]=-1;
	sta['U'][0]=-1;
	sta['U'][1]=0;
	sta['D'][0]=1;
	sta['D'][1]=0;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<string> s(n+1);
		for(int i=1;i<=n;i++){
			cin>>s[i];
			s[i]=' '+s[i];
		}
		vector<vector<int> > vis(n+2,vector<int> (m+2)),ans,vis1;
		ans=vis1=vis;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(!vis[i][j]){
					int x=i,y=j;
					stack<int> q,qq;
					do{
						q.push(x);
						qq.push(y);
						vis[x][y]=true;
						char ch=s[x][y];
						x+=sta[ch][0];
						y+=sta[ch][1];
						
					}while(!vis[x][y]&&x<=n&&x>=1&&y<=m&&y>=1);
					
					if(!(x<=n&&x>=1&&y<=m&&y>=1)||ans[x][y]){
						int now=ans[x][y];
						while(q.size()){
							int xx=q.top(),yy=qq.top();
							q.pop(),qq.pop();
							ans[xx][yy]=now+1;
							now=ans[xx][yy];
						}
					}else{
						stack<int> xxx,yyy;
						int now=0;
						while(q.size()){
							int xx=q.top(),yy=qq.top();
							q.pop(),qq.pop();
							xxx.push(xx),yyy.push(yy);
							if(xx==x&&yy==y){
								int v=xxx.size();
								while(xxx.size()){
									ans[xxx.top()][yyy.top()]=v;
									xxx.pop(),yyy.pop();
								}
								now=ans[xx][yy];
								continue;
							}
							ans[xx][yy]=now+1;
							now=ans[xx][yy];
						}
					}
				}
			}
		}
		int outx=1,outy=1,max1=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(max1<ans[i][j]){
					max1=ans[i][j];
					outx=i,outy=j;
				}
			}
		}
		cout<<outx<<" "<<outy<<" "<<max1<<endl;
	}
	return 0;
}