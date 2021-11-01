// Problem: 盾与战锤
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/11180/C
// Memory Limit: 524288 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<ll> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin()+1,a.end(),greater<ll>());
	vector<ll> sum(n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=((n+i-1)/i);
		ll ans=0;
		int res=-1;
		while(l<=r){
			int mid=(l+r)>>1;
			int r1=min(n,i*mid),l1=(mid-1)*i;
			if(sum[r1]-sum[l1]>m){
				res=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		if(res!=-1){
			ans=sum[min(res*i,n)]-res*m;
		}
		cout<<ans<<endl;
	}
	return 0;
}