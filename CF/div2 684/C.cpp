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
#define rev(a,b) (s[a][b]=(s[a][b]=='0'?'1':'0'))
char s[105][105];
struct node{
	int x,y,xx,yy,xxx,yyy;
};
int main()
{
	int i,j;
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
		vector<node>ans(0);
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<=m;j++){
				if(s[i][j]=='1'){
					if(j!=m){
						ans.push_back((node){i,j,i+1,j,i,j+1});
						s[i][j]='0';
						rev(i+1,j);
						rev(i,j+1);
					}else{
						ans.push_back((node){i,j,i+1,j,i+1,j-1});
						s[i][j]='0';
						rev(i+1,j);
						rev(i+1,j-1);
					}
				}
			}
		}
		for(int j=1;j<=m-2;j++){
			if(s[n-1][j]=='1'){
				ans.push_back((node){n-1,j,n-1,j+1,n,j});
				s[n-1][j]='0';
				rev(n-1,j+1);
				rev(n,j);
			}
			if(s[n][j]=='1'){
				ans.push_back((node){n,j,n-1,j+1,n,j+1});
				s[n][j]='0';
				rev(n-1,j+1);
				rev(n,j+1);
			}
		}
		while(1){
			int cnt=0;
			for(int i=n-1;i<=n;i++){
				for(int j=m-1;j<=m;j++){
					if(s[i][j]=='1'){
						cnt++;
					}
				}
			}
			if(cnt==4){
				ans.push_back(node{n-1,m-1,n-1,m,n,m-1});
				ans.push_back(node{n,m,n-1,m,n,m-1});
				ans.push_back(node{n-1,m-1,n-1,m,n,m});
				ans.push_back(node{n-1,m-1,n,m-1,n,m});
			}
			if(cnt==3){
				node t;
				int abc=0;
				for(int i=n-1;i<=n;i++){
					for(int j=m-1;j<=m;j++){
						if(s[i][j]=='1'){
							abc++;
							if(abc==1){
								t.x=i;
								t.y=j;
							}
							if(abc==2){
								t.xx=i;
								t.yy=j;
							}
							if(abc==3){
								t.xxx=i;
								t.yyy=j;
							}
						}
					}
				}
				ans.push_back(t);
			}
			if(cnt==4||cnt==3||cnt==0){
				break;
			}
			if(cnt==2){
				node t;
				bool flag=true;
				for(int i=n-1;i<=n&&flag;i++){
					for(int j=m-1;j<=m&&flag;j++){
						if(s[i][j]=='1'){
							t.x=i;
							t.y=j;
							flag=false;
							break;
						}
					}
				}
				int now=0;
				for(int i=n-1;i<=n;i++){
					for(int j=m-1;j<=m;j++){
						if(s[i][j]=='0'){
							now++;
							if(now==1){
								t.xx=i;
								t.yy=j;
							}
							if(now==2){
								t.xxx=i;
								t.yyy=j;
							}
						}
					}
				}
				rev(t.x,t.y);
				rev(t.xx,t.yy);
				rev(t.xxx,t.yyy);
				ans.push_back(t);
			}
			if(cnt==1){
				node t;
				bool flag=true;
				for(int i=n-1;i<=n&&flag;i++){
					for(int j=m-1;j<=m&&flag;j++){
						if(s[i][j]=='1'){
							t.x=i;
							t.y=j;
							flag=false;
							break;
						}
					}
				}
				int now=0;
				for(int i=n-1;i<=n;i++){
					for(int j=m-1;j<=m;j++){
						if(s[i][j]=='0'){
							now++;
							if(now==1){
								t.xx=i;
								t.yy=j;
							}
							if(now==2){
								t.xxx=i;
								t.yyy=j;
							}
						}
					}
				}
				rev(t.x,t.y);
				rev(t.xx,t.yy);
				rev(t.xxx,t.yyy);
				ans.push_back(t);
			}
		}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].x<<" "<<ans[i].y<<" "<<ans[i].xx<<" "<<ans[i].yy<<" "<<ans[i].xxx<<" "<<ans[i].yyy<<endl;
		}
	}
	return 0;
}