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
struct nodes{
	int v,flag;
	bool operator < (const nodes &a) const {
		return v>a.v;
	}
}num[max_n];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t,n,m,k;
	cin>>t;
	while(t--){
		cin>>n>>k;
		for(i=1;i<=n;i++){
			cin>>num[i].v;
			num[i].flag=0;
		}
		for(i=n+1;i<=2*n;i++){
			cin>>num[i].v;
			num[i].flag=1;
		}
		sort(num+1,num+1+2*n);
		int ans=0;
		int cnt=0;
		for(i=1;i<=2*n&&cnt!=n;i++){
			if(k){
				ans+=num[i].v;
				//cout<<num[i].v<<endl;
				k-=num[i].flag;
				cnt++;
			}else{
				if(!num[i].flag){
					ans+=num[i].v;
					cnt++;

				//cout<<num[i].v<<endl;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}