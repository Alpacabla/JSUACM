#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
int main()
{
	int n;
	int a,b;
	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&a,&b);
		if(a%b==0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}

	return 0;
}