// Problem: E. Messages
// Contest: Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1612/problem/E
// Memory Limit: 512 MB
// Time Limit: 3000 ms
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
const int max_n=2e5+5;
int cnt[max_n][21];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> m(n+1),k(n+1);
	for(int i=1;i<=n;i++){
		cin>>m[i]>>k[i];
		cnt[m[i]][k[i]]++;
	}
	vector<int> ans;
	double max1=-1;
	for(int i=1;i<=min(20,n);i++){
		vector<pair<int,int> > a((int)2e5+1);
		for(int j=1;j<=n;j++)
			a[m[j]].first+=min(i,k[j]);
		for(int j=1;j<=2e5;j++){
			// for(int k=1;k<=20;k++){
				// a[j].first+=min(i,k)*cnt[j][k];
			// }
			a[j].second=j;
		}
		sort(a.begin()+1,a.end());
		int sum=0;
		for(int j=2e5;j>2e5-i;j--){
			sum+=a[j].first;
		}
		if(sum*1.0/i>max1){
			ans.resize(0);
			for(int j=2e5;j>2e5-i;j--){
				ans.push_back(a[j].second);
			}
			max1=sum*1.0/i;
		}
	}
	cout<<ans.size()<<endl;
	for(auto v:ans) cout<<v<<" ";
	cout<<endl;
	return 0;
}