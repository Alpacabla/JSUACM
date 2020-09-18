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
ll now[100000];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n,m;
	ll lim=1e9;
	now[0]=2;
	for(i=1;;i++){
		now[i]=now[i-1]+((ll)(i+1)*3-1);
		if(now[i]>=lim) break;
	}
	//i++;
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int ans=0;
		while(n>=2){
			int k=lower_bound(now,now+i,(ll)n)-now;
			if(n>=now[k]){
				n-=now[k];
			}else{
				if(k==0) break;
				n-=now[k-1];
			}
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}