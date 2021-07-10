// Problem: E. Air Conditioners
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int tt;
	cin>>tt;
	while(tt--){
		int n,k;
		cin>>n>>k;
		vector<int> a(k+1),t(k+1);
		for(int i=1;i<=k;i++){
			cin>>a[i];
		}
		for(int i=1;i<=k;i++){
			cin>>t[i];
		}
		vector<int> ind(k+1);
		for(int i=1;i<=k;i++) ind[i]=i;
		sort(ind.begin()+1,ind.end(),[&a](int aa,int bb) -> bool{
			return a[aa]<a[bb];
		});
		// for(int i=1;i<=k;i++){
			// cout<<ind[i]<<endl;
		// }
		vector<int> ans(n+1);
		vector<int> min1(n+1);
		int nowt=int_inf;
		int l=1;
		for(int i=1;i<=n;i++){
			if(l<=k&&i==a[ind[l]]){
				if(nowt>t[ind[l]]){
					nowt=t[ind[l]];
				}
				l++;
			}
			min1[i]=nowt;
			nowt++;
		}
		nowt=int_inf;
		int r=k;
		for(int i=n;i>=1;i--){
			if(r>=1&&i==a[ind[r]]){
				if(nowt>t[ind[r]]){
					nowt=t[ind[r]];
				}
				r--;
			}
			ans[i]=min(nowt,min1[i]);
			nowt++;
		}
		/*for(int i=1;i<=k;i++){
			ans[a[i]]=t[i];
		}*/
		for(int i=1;i<=n;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}