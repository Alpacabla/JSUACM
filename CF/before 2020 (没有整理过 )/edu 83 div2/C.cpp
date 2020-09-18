#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
typedef unsigned long long int ull;
const ull INF=1e16;
ull num[35];
ull x[105][100];
int cnt1[105];
bool vis[105];
int main()
{
	int i,j,k;
	ull z;
	int n;
	int t;
	scanf("%d",&t);
	int a=1,b=2;
	swap(a,b);
	printf("%d %d",a,b);
	for(i=2;i<=100;i++){
		for(z=1,j=0;z<=INF;z*=i){
			x[i][j++]=z;
			cnt1[i]++;
		}
	}
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%llu",num+i);
		}
		sort(num,num+n);
		memset(vis,false,sizeof(vis));
		j=n-1;
		while(j!=-1){
			for(i=cnt1[k];i>=0;i--){
				if(num[j]&&!vis[i]&&num[j]>=x[k][i]){
					num[j]-=x[k][i];
					vis[i]=true;
				}
			}
			if(num[j]!=0) break;
			else j--;
		}
		if(j==-1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}