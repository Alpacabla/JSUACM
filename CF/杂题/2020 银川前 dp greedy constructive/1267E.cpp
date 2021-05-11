// Problem: E. Elections
// Contest: Codeforces - 2019-2020 ICPC, NERC, Northern Eurasia Finals (Unrated, Online Mirror, ICPC Rules, Teams Preferred)
// URL: https://codeforces.com/problemset/problem/1267/E
// Memory Limit: 512 MB
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<vector<int> >a(n+1,vector<int>(m+1));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[j][i];
		}
	}
	int ans=m+1;
	vector<int> out;
	for(int i=1;i<n;i++){
		vector<int> d(m+1),ind(m+1);
		int sum=0;
		for(int j=1;j<=m;j++){
			d[j]=a[i][j]-a[n][j];
			sum+=d[j];
			ind[j]=j;
		}
		sort(ind.begin()+1,ind.end(),[&d](const int a,const int b) -> bool{
			return d[a]<d[b];
		});
		sort(d.begin()+1,d.end());
		if(sum>=0){
			out.resize(0);
			ans=min(ans,0);
			break;
		}
		for(int j=1;j<=m;j++){
			sum-=d[j];
			if(sum>=0){
				if(ans>j){
					ans=j;
					out.resize(j);
					for(int k=0;k<j;k++){
						out[k]=ind[k+1];
					}
				}
				break;
			}
		}
	}
	cout<<ans<<endl;
	for(int i=0;i<out.size();i++){
		cout<<out[i]<<" ";
	}
	cout<<endl;
	return 0;
}