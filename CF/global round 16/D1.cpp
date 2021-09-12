// Problem: D1. Seating Arrangements (easy version)
// Contest: Codeforces - Codeforces Global Round 16
// URL: https://codeforces.com/contest/1566/problem/D1
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
		int n,m;
		cin>>n>>m;
		struct node{
			int a,b;
			bool operator < (const node aa){
				if(a==aa.a) return aa.b<b;
				else return a<aa.a;
			}
		};
		vector<node> s(m+1);
		
		vector<node> ss(m+1);
		for(int i=1;i<=m;i++){
			cin>>s[i].a;
			s[i].b=i;
			
			ss[i].a=s[i].a;
		}
		
		sort(s.begin()+1,s.end());
		for(int i=1;i<=m;i++){
			ss[s[i].b].b=i;
		}
		int ans=0;
		vector<int> val(m+1);
		for(int i=1;i<=m;i++){
			for(int j=1;j<ss[i].b;j++){
				ans+=val[j];
			}
			val[ss[i].b]=1;
			//cout<<ss[i].b<<" ";
		}
		//cout<<endl;
		cout<<ans<<endl;
	}
	
	return 0;
}