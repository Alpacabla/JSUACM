// Problem: C. Two Arrays
// Contest: Codeforces - Codeforces Round #755 (Div. 2, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.com/contest/1589/problem/C
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
		int n;
		cin>>n;
		vector<int> a(202),b(202);
		for(int i=1;i<=n;i++){
			int v;
			cin>>v;
			a[v+101]++;
		}
		for(int i=1;i<=n;i++){
			int v;
			cin>>v;
			b[v+101]++;
		}
		bool flag=true;
		for(int i=1;i<=201;i++){
			int mm=min(b[i],a[i-1]);
			b[i]-=mm;
			a[i-1]-=mm;
			if(a[i-1]>0) flag=false;
			
			mm=min(b[i],a[i]);
			b[i]-=mm;
			a[i]-=mm;
			if(b[i]!=0) flag=false;
			
		}
		cout<<(flag?"YES":"NO")<<endl;
	}
	
	
	return 0;
}