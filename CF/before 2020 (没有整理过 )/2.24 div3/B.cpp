#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int max_n=1e2+5;
int num[max_n],k;
bool book[max_n];
int main()
{
	int i;
	int n,m;
	int t;
	scanf("%d",&t);
	while(t--){
		int flag=1;
		scanf("%d %d",&n,&m);
		memset(book,0,sizeof(book));
		int ind;
		for(i=1;i<=n;i++) scanf("%d",num+i);
		for(i=1;i<=m;i++) scanf("%d",&ind),book[ind]=true;
		i=1;
		while(i<n){
			k=i;
			while(i<n&&book[i]){
				i++;
			}
			i++;
			sort(num+k,num+i);
		}
		for(i=1;i<n;i++){
			if(num[i]>num[i+1]){
				flag=0;
				break;
			}
		}
		if(flag==0){
			printf("NO\n");
		}else printf("YES\n");
	}
	return 0;
}