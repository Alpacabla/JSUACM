// Problem: C. Portal
// Contest: Codeforces - Codeforces Round #745 (Div. 2)
// URL: https://codeforces.com/contest/1581/problem/C
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
		int n,m;
		cin>>n>>m;
		vector<string> s(n+1);
		for(int i=1;i<=n;i++){
			cin>>s[i];
			s[i]=" "+s[i];
		}
		vector<vector<int> >sum(n+1,vector<int> (m+1));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(s[i][j]=='1');
			}
		};
		auto get1=[&sum](int x,int y,int x1,int y1) -> int{
			return sum[x][y]-sum[x1-1][y]-sum[x][y1-1]+sum[x1-1][y1-1];
		};
		auto get0=[&get1](int x,int y,int x1,int y1) -> int{
			return (x-x1+1)*(y-y1+1)-get1(x,y,x1,y1);
		};
		auto getv=[&get0,&get1](int x,int y,int x1,int y1) ->int{
			int res=0;
			res+=get0(x-1,y,x1+1,y);
			res+=get1(x-1,y-1,x1+1,y1+1);
			res+=get0(x,y-1,x,y1+1);
			res+=get0(x1,y-1,x1,y1+1);
			res+=get0(x-1,y1,x1+1,y1);
			return res;
		};
		int ans=int_inf;
		for(int i=1;i<=n;i++){
			for(int j=i+4;j<=n;j++){
				for(int k=4,l=1;k<=m;k++){
					int newl=k-3;
					int v1=getv(j,k,i,l);
					int v2=getv(j,k,i,newl);
					if(v2<v1) l=newl,v1=v2;
					ans=min(ans,v1);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}