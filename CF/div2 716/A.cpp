// Problem: A. Perfectly Imperfect Array
// Contest: Codeforces - Codeforces Round #716 (Div. 2)
// URL: https://codeforces.com/contest/1514/problem/A
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
		int n;
		cin>>n;
		vector<int>a(n+1);
		bool flag=true;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			int k=sqrt(a[i]);
			if(k*k!=a[i]){
				flag=false;
			}
		}
		if(!flag){
			cout<<"YES"<<endl;
		}else cout<<"NO"<<endl;
		
	}
	return 0;
}