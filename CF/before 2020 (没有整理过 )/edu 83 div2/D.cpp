#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
const int MOD=998244353;
int main()
{
	int i;
	int sum=0;
	for(i=1;i<=1337;i++){
		sum+=i;
	}
	sum-=(1337-42+3);
	int ans=0;
	for(i=1;i<=42;i++){
		ans+=sum*i;
		if(ans>MOD) printf("no");
	}
	//ans-=42*42;
	//ans+=sum;
	printf("%d\n",ans);

	return 0;
}