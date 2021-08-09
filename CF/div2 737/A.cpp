// Problem: A. Ezzat and Two Subsequences
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/A
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
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> a(n+1);
		for(int i=1;i<=n;i++){
			int k;
			scanf("%d",&k);
			a[i]=k;
		}
		sort(a.begin()+1,a.end());
		double sum=0.0;
		for(int i=1;i<n;i++) sum+=a[i];
		printf("%.8lf\n",sum/(n-1)+a[n]);
	}
	
	return 0;
}