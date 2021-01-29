#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long int ll;
const int INF=0x3f3f3f3f;
int main()
{
	ll u,v;
	ll d;
	scanf("%lld%lld",&u,&v);
	d=v-u;
	if(u>v||(d%2)){
		printf("-1\n");
	}else{
		if(u==v){
			if(u==0) printf("0\n");
			else{
				printf("1\n%lld\n",u);
			}
		}else{
			d/=2;
			ll k=d+u;
			if((k^d)==u&&k+d==v){
				printf("2\n%lld %lld\n",k,d);
			}else{
				printf("3\n%lld %lld %lld\n",u,d,d);
			}
		}
	}
	return 0;
}