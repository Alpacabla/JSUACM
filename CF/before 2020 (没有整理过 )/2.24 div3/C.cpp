#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int ans[30];
int d[800000];
char s[200010];
int n,m;
int read()
{
	int num=0;
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) num=num*10+ch-'0';
	return num;
}
void update(int ind,int add)
{
	while(ind<=n){
		d[ind]+=add;
		ind+=ind&-ind;
	}
}
int check(int ind)
{
	int sum=0;
	while(ind){
		sum+=d[ind];
		ind-=ind&-ind;
	}
	return sum;
}
int main()
{
	int temp;
	int t;
	int i;
	scanf("%d",&t);
	while(t--){
		memset(d,0,sizeof(d));
		memset(ans,0,sizeof(ans));
		scanf("%d %d",&n,&m);
		scanf("%s",s+1);
		d[0]=0;
		for(i=0;i<m;i++){
			temp=read();
			update(1,1);
			update(temp+1,-1);
		}
		update(1,1);
		update(n+1,-1);
		for(i=1;i<=n;i++){
			ans[s[i]-'a'+1]+=check(i);
		}
		for(i=1;i<=26;i++){
			if(i!=1) printf(" %d",ans[i]);
			else printf("%d",ans[i]);
		}
		printf("\n");
	}
	return 0;
}