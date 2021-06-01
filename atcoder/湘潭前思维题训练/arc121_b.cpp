// Problem: B - RGB Matching
// Contest: AtCoder - NOMURA Programming Contest 2021(AtCoder Regular Contest 121)
// URL: https://atcoder.jp/contests/arc121/tasks/arc121_b?lang=en
// Memory Limit: 1024 MB
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
	int n;
	cin>>n;
	vector<ll> a[3];
	vector<int> ind(150);
	ind['R']=0;
	ind['G']=1;
	ind['B']=2;
	for(int i=1;i<=(n<<1);i++){
		ll k;
		char ch;
		cin>>k>>ch;
		a[ind[ch]].push_back(k);
	}
	bool flag=false;
	int z=0;
	for(int i=0;i<3;i++){
		sort(a[i].begin(),a[i].end());
		if(a[i].size()%2==1){
			flag=true;
		}
	}
	for(int i=0;i<3;i++){
		if(a[i].size()%2==0){
			z=i;
		}
	}
	if(!flag){
		cout<<0<<endl;
		return 0;
	}else{
		if(z){
			swap(a[0],a[z]);
		}
		ll ans=ll_inf;
		for(int i=0;i<a[1].size();i++){
			for(int j=0;j<a[2].size();j++){
				ans=min(ans,abs(a[1][i]-a[2][j]));
			}
		}
		struct node{
			ll val;
			int k;
			bool operator (const node &a) const {
				return val<a.val;
			}
		};
		
		auto f = [&a](int u,int w) -> ll {
			ll res=ll_inf;
			for(int i=0,j=0;i<a[u].size();i++){
				while(j+1<a[w].size()){
					if(abs(a[w][j+1]-a[u][i])<abs(a[w][j]-a[u][i])) j++;
					else break;
				}
				res=min(res,abs(a[w][j]-a[u][i]));
			}
			return res;
		};
		cout<<min(f(1,2),f(0,1)+f(0,2))<<endl;
	}
	return 0;
}