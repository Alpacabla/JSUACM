// Problem: D. Vupsen, Pupsen and 0
// Contest: Codeforces - Codeforces Round #750 (Div. 2)
// URL: https://codeforces.com/contest/1582/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		vector<int> b(n+1);
		if(n%2==0){
			for(int i=1;i<=n;i+=2){
				int v=a[i]*a[i+1];
				b[i]=v/a[i];
				b[i+1]=-v/a[i+1];
			}
			for(int i=1;i<=n;i++){
				cout<<b[i]<<" ";
			}
			cout<<endl;
		}else{
			struct node{
				int v,ind;
			};
			vector<node> aa(n+1);
			for(int i=1;i<=n;i++){
				aa[i].v=a[i];
				aa[i].ind=i;
			}
			sort(aa.begin()+1,aa.end(),[](const node a,const node b) -> bool {
				return abs(a.v)<abs(b.v);
			});
			for(int i=1;i<=3;i++){
				int sum=0;
				for(int j=1;j<=3;j++){
					if(j!=i){
						sum+=aa[j].v;
					}
				}
				b[aa[i].ind]=sum;
				if(b[aa[i].ind]!=0){
					int tot=1;
					for(int j=1;j<=3;j++){
						if(i!=j){
							b[aa[j].ind]=-aa[i].v;
						}
					}
					break;
				}
			}
			
			sort(aa.begin()+4,aa.end(),[](const node a,const node b) -> bool {
				return a.v<b.v;
			});
			
			for(int i=4;i<=n;i+=2){
				int vv=aa[i].v*aa[i+1].v/__gcd(aa[i].v,aa[i+1].v);
				b[aa[i].ind]=vv/aa[i].v;
				b[aa[i+1].ind]=-vv/aa[i+1].v;
			}
			ll res=0;
			for(int i=1;i<=n;i++){
				res+=a[i]*b[i];
				cout<<b[i]<<" ";
			}
			cout<<endl;
			//cout<<res<<endl;
		}
	}
	return 0;
}