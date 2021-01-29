#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
ll num[500];
bool v[500][65];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k;
	int n;
	ll ans=-1;
	cin>>n;
	set<ll>sets;
	for(i=1;i<=n;i++){
		ll num;
		cin>>num;
		sets.insert(num);
	}
	int cnt=0;
	for(set<ll>::iterator it=sets.begin();it!=sets.end();it++){
		num[cnt]=*it;
		ans=max(ans,*it);
		cnt++;
	}
	if(cnt>=2){
		for(i=0;i<cnt;i++){
			for(j=i+1;j<cnt;j++){
				ans=max(ans,num[i]|num[j]);
			}
		}
	}
	for(i=0;i<cnt;i++){
		for(j=i+1;j<cnt;j++){
			for(k=j+1;k<cnt;k++){
				ans=max(ans,num[i]|num[j]|num[k]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}