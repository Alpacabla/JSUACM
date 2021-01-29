#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int max_n=1e3+5;
int parent[max_n];
int root[max_n][2];
int ind[max_n];
int in[max_n][2];
int vis[max_n];
/*struct data{
	int a,b;
	bool operator < (const data &t) const{
		return a<t.a;
	}
}num[max_n];*/
int find_root(int a)
{
	return ((parent[a]==a)?a:parent[a]=find_root(parent[a]));
}
void merge(int a,int b)
{
	int a1=find_root(a),b1=find_root(b);
	parent[a1]=b1;
	vis[b1]=1;
}
int main()
{
	int ver;
	int i;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++) parent[i]=i;
	for(i=1;i<n;i++){
		scanf("%d %d",in[i],in[i]+1);
		//scanf("%d %d",&num[i].a,&num[i].b);
		//vis[in[i][0]]=vis[in[i][1]]=1;
	}
	/*sort(num+1,num+n);
	for(i=1;i<n;i++){
		in[i][0]=num[i].a;
		in[i][1]=num[i].b;
		printf("%d %d\n",in[i][0],in[i][1]);
	}*/
	if(n==2){
		printf("? %d %d\n",in[1][0],in[1][1]);
		fflush(stdout);
		scanf("%d",&ver);
		printf("! %d\n",ver);
		return 0;
	}
	for(i=1;i<n;i++){
		/*if(ind[in[i][0]]==1&&ind[in[i][1]]==1){
			continue;
		}*/
		root[in[i][0]][ind[in[i][0]]]=in[i][1];
		root[in[i][1]][ind[in[i][1]]]=in[i][0];
		ind[in[i][0]]++;
		ind[in[i][1]]++;
		if(ind[in[i][0]]==2){
			printf("? %d %d\n",root[in[i][0]][0],root[in[i][0]][1]);
			fflush(stdout);
			scanf("%d",&ver);
			if(ver==-1){
				printf("! -2\n");
				return 0;
			}
			merge(in[i][0],ver);
			merge(root[in[i][0]][0],ver);
			merge(root[in[i][0]][1],ver);
			ind[in[i][0]]=0;
			if(ind[root[in[i][0]][0]]!=2) ind[root[in[i][0]][0]]=0;
			else ind[root[in[i][0]][0]]=1;
			if(ind[root[in[i][0]][1]]!=2) ind[root[in[i][0]][1]]=0;
			else ind[root[in[i][0]][1]]=1;
		}else{
			if(ind[in[i][1]]==2){
				printf("? %d %d\n",root[in[i][1]][0],root[in[i][1]][1]);
				fflush(stdout);
				scanf("%d",&ver);
				if(ver==-1){
					printf("! -2\n");
					return 0;
				}
				merge(in[i][1],ver);
				merge(root[in[i][1]][0],ver);
				merge(root[in[i][1]][1],ver);
				ind[in[i][0]]=0;
				ind[in[i][1]]=0;
				ind[root[in[i][1]][0]]=0;
				ind[root[in[i][1]][1]]=0;
			}
		}
	}
	for(i=1;i<n;i++){
		if(ind[i]==1){
			ind[root[i][0]]=0;
			ind[i]=0;
			if(parent[i]==i&&parent[root[i][0]]==root[i][0]){
				printf("? %d %d\n",i,root[i][0]);
				fflush(stdout);
				scanf("%d",&ver);
				if(ver==-1){
					printf("! -2\n");
					return 0;
				}
				merge(i,ver);
				merge(root[i][0],ver);
			}else{
				if(parent[i]==i){
					merge(i,root[i][0]);
				}else{
					if(parent[root[i][0]]==root[i][0]){
						merge(root[i][0],i);
					}else{
						printf("? %d %d\n",i,root[i][0]);
						fflush(stdout);
						scanf("%d",&ver);
						if(ver==-1){
							printf("! -2\n");
							return 0;
						}
						merge(i,ver);
						merge(root[i][0],ver);
					}
				}
			}
		}
	}
	int cnt=0;
	int ans;
	for(i=1;i<=n;i++){
		if(parent[i]==i&&vis[i]){
			printf("! %d\n",i);
			return 0;
			cnt++;
			ans=i;
		}
	}
	if(cnt>1) printf("! -1\n");
	else printf("! %d\n",ans);
	return 0;
}