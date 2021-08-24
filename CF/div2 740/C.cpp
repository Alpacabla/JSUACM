// Problem: C. Deep Down Below
// Contest: Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
// URL: https://codeforces.com/contest/1561/problem/C
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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> ind(n+1),val(n+1);
		vector<vector<int> > a(n+1,vector<int>(0));
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			ind[i]=i;
			while(k--){
				int z;
				cin>>z;
				a[i].push_back(z);
			}
		}
		for(int i=1;i<=n;i++){
			val[i]=a[i][0]+1;
			for(int j=0;j<a[i].size();j++){
				val[i]=max(val[i],a[i][j]+1-j);
			}
		}
		sort(ind.begin()+1,ind.end(),[&val](const int aa,const int bb) -> bool{
			return val[aa]<val[bb];
		});
		int res=1e9+1;
		int l=2,r=1e9+1;
		while(l<=r){
			int mid=(l+r)>>1;
			bool flag=true;
			int vvv=mid;
			for(int o=1;o<=n;o++){
				int &i=ind[o];
				if(vvv<val[i]){
					flag=false;
					break;
				}else{
					vvv+=a[i].size();
				}
			}
			if(flag){
				res=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		cout<<res<<endl;
	}
	return 0;
}