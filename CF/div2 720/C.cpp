// Problem: C. Nastia and a Hidden Permutation
// Contest: Codeforces - Codeforces Round #720 (Div. 2)
// URL: https://codeforces.com/contest/1521/problem/C
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
int vis[max_n];
int tot;
inline void get_ab(int &a,int &b)
{
	a=++tot;
	b=++tot;
	return ;
}
int ans[max_n];
inline void pri(int t,int x,int i,int j){
	cout<<"? "<<t<<" "<<i<<" "<<j<<" "<<x<<endl;
	cout.flush();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		memset(vis,0,sizeof(int)*(n+1));
		tot=0;
		for(int i=1;i<=n/2;i++){
			int a,b;
			get_ab(a,b);
			pri(1,n-1,a,b);
			int max1,min1;
			cin>>max1;
			if(max1==n-1){
				pri(1,n-1,b,a);
				cin>>max1;
			}
			pri(2,1,a,b);
			cin>>min1;
			if(min1==2){
				pri(2,1,b,a);
				cin>>min1;
			}
			vis[a]=min1,vis[b]=max1;
			pri(1,max1-1,a,b);
			cin>>max1;
			if(max1!=vis[b]){
				swap(vis[a],vis[b]);
			}
		}
		if(tot!=n){
			vector<bool> k(n+1);
			for(int i=1;i<=n;i++){
				k[vis[i]]=true;
			}
			int res=0;
			for(int i=1;i<=n;i++){
				if(!k[i]){
					res=i;
					break;
				}
			}
			vis[n]=res;
		}
		cout<<"! ";
		for(int i=1;i<=n;i++){
			cout<<vis[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}