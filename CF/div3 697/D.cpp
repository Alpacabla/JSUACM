/*
link: 
tags: 
*/
#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=2e5+5;
ll dp[max_n<<1];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int t;
	cin>>t;
	while(t--){
		int n;
		ll m;
		cin>>n>>m;
		int tot=0;
		int sum=0;
		vector<int> a(n+1),b(n+1),ind(n+1);
		vector<double> v(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ind[i]=i;
		}
		for(int i=1;i<=n;i++){
			cin>>b[i];
			sum+=b[i];
			v[i]=a[i]*1.0/b[i];
		}
		sort(ind.begin()+1,ind.end(),[b,v](const int aa,const int bb) -> bool {
			if(v[aa]==v[bb]) return b[aa]<b[bb];
			else return v[aa]>v[bb];
		});
		ll now=0;
		ll ans=0;
		for(int i=1;i<=n;i++){
			now+=a[ind[i]];
			ans+=b[ind[i]];
			if(now>=m){
				break;
			}
		}
		if(now>=m) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}