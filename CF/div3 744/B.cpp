// Problem: B. Shifting Sort
// Contest: Codeforces - Codeforces Round #744 (Div. 3)
// URL: https://codeforces.com/contest/1579/problem/B
// Memory Limit: 256 MB
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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1),b(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b.begin()+1,b.end());
		vector<tuple<int,int,int> > ans;
		auto rotate = [](vector<int> &a,int l,int r,int v) -> void{
			vector<int> b=a;
			for(int i=l;i<=r;i++){
				int to=i+v;
				if(to>r){
					to=l+(i+v)%r-1;
				}
				a[i]=b[to];
			}
		};
		for(int i=1;i<=n;i++){
			int k=b[i];
			int ind;
			for(int j=i;j<=n;j++){
				if(a[j]==k){
					ind=j;
					break;
				}
			}
			int v=ind-i;
			if(v){
				ans.push_back({i,n,v});
				rotate(a,i,n,v);
				// for(int i=1;i<=n;i++){
					// cout<<a[i]<<" ";
				// }
				// cout<<endl;
			}
		}
		cout<<ans.size()<<endl;
		for(auto [a,b,c]:ans){
			cout<<a<<" "<<b<<" "<<c<<endl;
		}
		
	}
	return 0;
}