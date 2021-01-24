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
struct node{
	int l,r;
};
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
		vector<node> a(n+1),b(n+1);
		for(int i=1;i<=n;i++){
			int l,r;
			cin>>l>>r;
			a[i].l=l;
			a[i].r=r;
			b[i]=a[i];
		}
		sort(a.begin()+1,a.end(),[](const node a,const node b) -> bool{
			return a.l<b.l;
		});
		sort(b.begin()+1,b.end(),[](const node a,const node b) -> bool{
			return a.r<b.r;
		});
		vector<int> aa(n+1),bb(n+1);
		for(int i=1;i<=n;i++){
			aa[i]=a[i].l;
			bb[i]=b[i].r;
		}
		int ans=int_inf;
		for(int i=1;i<=n;i++){
			int cnt=0;
			int k1=int(upper_bound(aa.begin()+1,aa.end(),a[i].r)-aa.begin());
			int k2=int(lower_bound(bb.begin()+1,bb.end(),a[i].l)-bb.begin());
			cnt+=k2-1;
			cnt+=n-k1+1;
			ans=min(ans,cnt);
		}
		cout<<ans<<endl;
	}
	return 0;
}