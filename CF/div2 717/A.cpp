// Problem: A. Tit for Tat
// Contest: Codeforces - Codeforces Round #717 (Div. 2)
// URL: https://codeforces.com/contest/1516/problem/A
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
		int n,k;
		int sum=0;
		cin>>n>>k;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int last=n;
		for(int i=1;i<n;i++){
			//while(last>=1&&a[last]==0) last--;
			while(k>=1&&a[i]>=1){
				a[i]--;
				a[last]++;
				k--;
			}
			if(k==0) break;
		}
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}