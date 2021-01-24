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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int sum1=0;
		vector<int> num(n+1),sum(n+1);
		for(int i=1;i<=n;i++){
			cin>>num[i];
			sum[i]=sum[i-1]+num[i];
			sum1+=num[i];
		}
		int ans=ll_inf;
		for(int i=1;i<=n;i++){
			int now=sum[i];
			int cnt=i-1;
			bool flag=true;
			if(sum1%now==0){
				int k=i;
				while(k<n){
					int q=sum[k]+now;
					int ind=(int)(lower_bound(sum.begin()+k+1,sum.end(),q)-sum.begin());
					if(ind!=(n+1)&&sum[ind]-sum[k]==now){
						cnt+=(ind-k-1);
						k=ind;
					}else{
						flag=false;
						break;
					}
				}
			}else{
				flag=false;
			}
			if(flag) ans=min(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}