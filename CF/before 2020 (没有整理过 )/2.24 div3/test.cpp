#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long int
using namespace std;
ll ans[30];
char s[200010];
int n,m;
int num[200010];
inline int read()
{
	int num1=0;
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';ch=getchar()) num1=num1*10+ch-'0';
	return num1;
}
int main()
{
	int t;
	int i;
	scanf("%d",&t);
	while(t--){
		memset(ans,0,sizeof(ans));
		scanf("%d %d",&n,&m);
		scanf("%s",s+1);
		for(i=1;i<=m;i++){
			num[i]=read();
		}
		sort(num+1,num+m+1);
		int now=m;
		int cnt=1;
		i=n;
		while(i>0){
			while(now!=0&&num[now]>=i){
				now--;
				cnt++;
			}
			ans[s[i]-'a'+1]+=(ll)cnt;
			i--;
		}
		for(i=1;i<=26;i++){
			if(i!=1) printf(" %lld",ans[i]);
			else printf("%lld",ans[i]);
		}
		printf("\n");
	}

	return 0;
}