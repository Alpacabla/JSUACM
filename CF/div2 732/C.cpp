// Problem: C. AquaMoon and Strange Sort
// Contest: Codeforces - Codeforces Round #732 (Div. 2)
// URL: https://codeforces.com/contest/1546/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		vector<int> a,b;
		for(int i=0;i<n;i++){
			int k;
			cin>>k;
			if(i%2==0) a.push_back(k);
			else b.push_back(k);
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		vector<int> res;
		for(int i=0;i<n;i++){
			if(i%2==0) res.push_back(a[i/2]);
			else res.push_back(b[i/2]);
		}
		bool flag=true;
		for(int i=0;i<n-1;i++){
			if(res[i]>res[i+1]){
				flag=false;
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	/*int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1),ind(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ind[i]=i;
		}
		sort(ind.begin()+1,ind.end(),[&a](const int aa,const int bb) -> bool{
			if(a[aa]==a[bb]) return aa<bb;
			else return a[aa]<a[bb];
		});
		bool flag=true;
		vector<int> vis(max_n);
		for(int i=1;i<=n;i++){
			//if(ind[i]>i){
				vis[a[ind[i]]]+=abs(ind[i]-i);
			//}
		}
		for(int i=0;i<max_n&&flag;i++){
			flag=(vis[i]%2==0);
		}
		cout<<(!flag?"NO":"YES")<<endl;
	}*/
	return 0;
}