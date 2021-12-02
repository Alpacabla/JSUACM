// Problem: C. Complex Market Analysis
// Contest: Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1609/problem/C
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
istream& operator >> (istream &is,vector<int> &v) {
	for(int i=1;i<v.size();i++){
		is>>v[i];
	}
	return is;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> vis(1e6+1);
	vis[1]=true;
	for(int i=2;i<=1e6;i++){
		if(!vis[i]){
			for(int j=i+i;j<=1e6;j+=i){
				vis[j]=true;
			}
		}
	} 
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> a(n+1);
		cin>>a;
		ll ans=0;
		for(int i=1;i<=k;i++){
			int cnt1=0,cnt2=0;
			int last=-1;
			for(int j=i;j<=n;j+=k){
				if(vis[a[j]]){
					if(a[j]==1){
						cnt2++;
						if(last!=-1){
							ans+=cnt1+1;
						}
					}else{
						cnt1=0,cnt2=0;
						last=-1;
					}
				}else{
					ans+=cnt2;
					cnt1=cnt2;
					cnt2=0;
					last=0;
				}
			}
		}
		cout<<ans<<endl;
	}
	
	
	return 0;
}