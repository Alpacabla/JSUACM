// Problem: D. Take a Guess
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define int ll
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
signed main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);
	// int a[10]={1,6,4,2,3,5,4};
	// for(int i=2;i<=7;i++){
		// cout<<(a[1]&a[i])<<endl;
		// cout<<(a[1]|a[i])<<endl;
	// }
	// cout<<(a[2]&a[3])<<endl;
	// cout<<(a[2]|a[3])<<endl;
	int n,k;
	cin>>n>>k;
	vector<int> v;
	for(int i=2;i<=n;i++){
		cout<<"and "<<1<<" "<<i<<endl;
		fflush(stdout);
		int k1,k2;
		cin>>k1;
		cout<<"or "<<1<<" "<<i<<endl;
		fflush(stdout);
		cin>>k2;
		v.push_back(k1+k2);
		//ind.push_back(i);
	}
	int k1,k2;
	cout<<"and "<<2<<" "<<3<<endl;
	fflush(stdout);
	cin>>k1;
	cout<<"or "<<2<<" "<<3<<endl;
	fflush(stdout);
	cin>>k2;
	k1+=k2;
	v.push_back(v[0]+v[1]-k1);
	ll vv=v[0]+v[1]-k1;
	sort(v.begin(),v.end());
	//ind.push_back(1);
	// sort(ind.begin(),ind.end(),[&v](const int a,const int b) -> bool{
		// return v[a]<v[b];
	// });
	cout<<"finish "<<v[k-1]-(vv/2)<<endl;
	fflush(stdout);
	return 0;
}