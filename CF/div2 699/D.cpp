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
char s[1005][1005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>(s[i]+1);
		}
		int x=-1,y=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(s[i][j]==s[j][i]){
					x=i,y=j;
				}
			}
		}
		bool flag=true;
		vector<int> ans(m+1);
		if(x!=-1){
			for(int i=0;i<=m;i++){
				if(i%2==0) ans[i]=x;
				else ans[i]=y;
			}
		}else{
			if(m%2==1){
				for(int i=0;i<=m;i++){
					ans[i]=(i%2)+1;
				}
			}else{
				int pos[3]={0};
				for(int i=1;i<=n;i++){
					for(int j=1;j<=n;j++){
						pos[s[i][j]-'a'+1]=j;
					}
					if(pos[1]&&pos[2]){
						pos[0]=i;
						break;
					}
					pos[1]=pos[2]=0;
				}
				if(pos[0]){
					if(m%4==0){
						for(int i=0;i<=m;i++){
							ans[i]=pos[0];
							if((i+1)%2==0) ans[i]=pos[1];
							if((i+1)%4==0) ans[i]=pos[2];
						}
					}else{
						for(int i=0;i<=m;i++){
							ans[i]=pos[0];
							if(i%4==0) ans[i]=pos[1];
							if((i+2)%4==0) ans[i]=pos[2];
						}
					}
				}else flag=false;
			}
		}
		if(flag){
			cout<<"YES"<<endl;
			for(int i=0;i<=m;i++){
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}else cout<<"NO"<<endl;
	}
	return 0;
}