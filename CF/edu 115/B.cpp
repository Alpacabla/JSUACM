// Problem: B. Groups
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1598/problem/B
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
		int n;
		cin>>n;
		vector<vector<int> >a(n+1,vector<int>(5+1));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=5;j++){
				cin>>a[i][j];
			}
		}
		bool flag=false;
		vector<int> vis(5+1);
		for(int i=1;i<=5;i++){
			for(int j=i+1;j<=5;j++){
				int cnt1,cnt2;
				cnt1=cnt2=0;
				int v=0;
				for(int k=1;k<=n;k++){
					if(a[k][i]==1&&a[k][j]==1){
						v++;
					}else{
						cnt1+=a[k][i]==1;
						cnt2+=a[k][j]==1;
					}
				}
				if(cnt1<n/2){
					v-=(n/2-cnt1);
					cnt1=n/2;
				}
				if(cnt2<n/2){
					v-=(n/2-cnt2);
					cnt2=n/2;
				}
				if(v>=0&&cnt1>=n/2&&cnt2>=n/2){
					flag=true;
				}
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	return 0;
}