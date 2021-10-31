// Problem: D. Red-Blue Matrix
// Contest: Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1606/problem/D
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
		vector<vector<int> > a(n+1,vector<int>(m+1));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		vector<int> ind(n+1);
		for(int i=1;i<=n;i++) ind[i]=i;
		sort(ind.begin()+1,ind.end(),[&a](int aa,int bb) -> bool{
			return a[aa][1]<a[bb][1];
		});
		vector<vector<int> > max1(n+2,vector<int>(m+2)),min1(n+2,vector<int>(m+2,int_inf));
		vector<vector<int> > max2=max1,min2=min1;
		
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				int ii=ind[i];
				max1[i][j]=max({max1[i-1][j],max1[i][j-1],a[ii][j]});
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=1;j<=m;j++){
				int ii=ind[i];
				min1[i][j]=min({min1[i+1][j],min1[i][j-1],a[ii][j]});
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=m;j>=1;j--){
				int ii=ind[i];
				min2[i][j]=min({min2[i-1][j],min2[i][j+1],a[ii][j]});
			}
		}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				int ii=ind[i];
				max2[i][j]=max({max2[i][j+1],max2[i+1][j],a[ii][j]});
			}
		}
		string s;
		for(int i=0;i<n;i++) s+=' ';
		bool flag=true;
		int cut;
		for(int j=1;j<m&&flag;j++){
			for(int i=1;i<n&&flag;i++){
				if(max1[i][j]<min1[i+1][j]&&min2[i][j+1]>max2[i+1][j+1]){
					flag=false;
					for(int v=1;v<=n;v++){
						if(v<=i) s[ind[v]-1]='B';
						else s[ind[v]-1]='R';
					}
					cut=j;
				}
			}
		}
		if(flag) cout<<"NO"<<endl;
		else{
			cout<<"YES"<<endl;
			cout<<s<<" "<<cut<<endl;
		}
	}
	return 0;
}