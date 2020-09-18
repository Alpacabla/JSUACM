#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int max_n=1e5+5;
int num[max_n];
int main()
{
	int t;
	scanf("%d",&t);
	int n;
	int i;
	while(t--){
		scanf("%d",&n);
		for(i=1;i<=n;i++){
			scanf("%d",num+i);
		}
		sort(num+1,num+n+1);
		num[0]=0;
		int cnt=0;
		for(i=1;i<=n;i++){
			if(num[i]>num[i-1]){
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}

	return 0;
}