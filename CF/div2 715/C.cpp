// Problem: C. The Sports Festival
// Contest: Codeforces - Codeforces Round #715 (Div. 2)
// URL: https://codeforces.com/contest/1509/problem/C
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
ll solve(vector<ll> &a,int k,int n)
{
	ll res=0;
	ll max1,min1;
	max1=min1=a[k];
	int l=k-1,r=k+1;
	while(1){
		bool flag=true;
		if(k==3) cout<<l<<" "<<r<<endl;
		res+=max1-min1;
		if(l<1&&r>n){
			break;
		}
		if(l<1){
			min1=min(min1,a[r]);
			max1=max(max1,a[r]);
			r++;
			continue;
		}
		if(r>n){
			min1=min(min1,a[l]);
			max1=max(max1,a[l]);
			l--;
			continue;
		}
		if((min1-a[l])*(n-r+1)+(max1-a[l])<(a[r]-max1)*(l)+(a[r]-min1)){
			min1=min(min1,a[l]);
			max1=max(max1,a[l]);
			l--;
		}else{
			min1=min(min1,a[r]);
			max1=max(max1,a[r]);
			r++;
		}
	}
	return res;
}
ll solve2(vector<ll> a,int lsize,int n)
{
	vector<ll> k(a.size());
	for(int i=1;i<=lsize;i++){
		k[i]=a[n-lsize+i];
	}
	for(int i=1;i<=n-lsize;i++){
		k[lsize+i]=a[n-lsize-i+1];
	}
	// for(int i=1;i<=n;i++){
		// cout<<k[i]<<" ";
	// }
	// cout<<endl;
	ll res=0;
	ll min1=k[1],max1=k[1];
	for(int i=1;i<=n;i++){
		max1=max(max1,k[i]);
		min1=min(min1,k[i]);
		res+=max1-min1;
	}
	return res;
}
ll solve3(vector<ll> a,int n)
{
	struct node{
		int v1,v2;
		bool operator < (const node z) const {
			return v1<z.v1;
		}
	}
	vector<> 
	for(int i=)
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	// cin>>t;
	// while(t--){
		int n;
		cin>>n;
		vector<ll> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a.begin()+1,a.end());
		ll ans=ll_inf;
		for(int i=0;i<=n;i++){
			ans=min(ans,solve2(a,i,n));
		}
		// for(int i=1;i<=n;i++){
			// ans=min(solve(a,i,n),ans);
		// }
		cout<<ans<<endl;
	//}
	return 0;
}