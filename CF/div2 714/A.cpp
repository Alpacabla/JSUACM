// Problem: F. Swapping Problem
// Contest: Codeforces - Divide by Zero 2021 and Codeforces Round #714 (Div. 2)
// URL: https://codeforces.com/contest/1513/problem/F
// Memory Limit: 512 MB
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
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<int> a(n+1);
		if(ceil((n-2)/2.0)<m){
			cout<<-1<<endl;
		}else{
			int k=n;
			int z=1;
			for(int i=2;i<=n-1&&z<=m;i+=2,z++){
				a[i]=k--;
			}
			if(z<=m){
				cout<<-1<<endl;
				continue;
			}
			for(int i=1;i<=n;i++){
				if(a[i]==0) a[i]=k--;
			}
			for(int i=1;i<=n;i++){
				cout<<a[i]<<" ";
			}
			cout<<endl;
		}
		
	}
	return 0;
}