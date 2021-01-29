#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int max_n=2e5+10;
char s[max_n];
int main()
{
	int t,i,len,k,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		len=strlen(s);k=0;ans=0;
		s[len]='R';
		s[len+1]='\0';
		for(i=0;i<=len;i++){
			k++;
			if(s[i]=='R'){
				if(k>ans) ans=k;
				k=0;
			}
		}
		if(k>ans) ans=k;
		printf("%d\n",ans);
	}
	return 0;
}