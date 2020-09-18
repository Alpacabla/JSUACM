#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
int cnt[2005];
int num[2005];
int vis[2005];
int new_vis[2005];
int new_cnt[2005];
int main()
{
	int n,h;
	int l,r;
	int i,j;
	int t;
	scanf("%d %d %d %d",&n,&h,&l,&r);
	for(i=0;i<n;i++){
		scanf("%d",num+i);
	}
	new_vis[0]=1;
	for(i=0;i<n;i++){
		for(j=0;j<h;j++){
			vis[j]=new_vis[j];
			cnt[j]=new_cnt[j];
		}
		memset(new_cnt,0,sizeof(new_cnt));
		memset(new_vis,0,sizeof(new_vis));
		for(j=0;j<h;j++){
			if(vis[j]){
				t=(j+num[i])%h;
				new_vis[t]=1;
				if(t>=l&&t<=r){
					new_cnt[t]=max(cnt[t],cnt[j]+1);
				}else{
					new_cnt[t]=max(cnt[t],cnt[j]);
				}
				t=(j+num[i]-1)%h;
				new_vis[t]=1;
				if(t>=l&&t<=r){
					new_cnt[t]=max(cnt[t],cnt[j]+1);
				}else{
					new_cnt[t]=max(cnt[t],cnt[j]);
				}
			}
		}
	}
	for(j=0;j<h;j++){
		vis[j]=new_vis[j];
		cnt[j]=new_cnt[j];
	}
	int ans=0;
	for(i=0;i<h;i++){
		if(cnt[i]>ans) ans=cnt[i];
	}
	printf("%d\n",ans);
	return 0;
}