// Problem: D. Guess the Permutation
// Contest: Codeforces - Codeforces Round #755 (Div. 2, based on Technocup 2022 Elimination Round 2)
// URL: https://codeforces.com/contest/1589/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
//#define endl '\n'
typedef long long int ll;
typedef unsigned long long int ull;
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
ll q(int l,int r){
	ll res;

	if(l!=r){
		cout<<"? "<<l<<" "<<r<<endl;
		cout.flush();
		cin>>res;
	}else{
		res=1;
	}

	return res;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		
		ll inv=q(1,n);
		int l=1,r=n,r1=n;
		while(l<=r){
			int mid=(l+r)>>1;
			ll v=q(1,mid);
			if(v==inv){
				r1=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		ll v=q(1,r1-1);
		int d=inv-v;
		int mm=r1-d;
		ll sum=1ll*d*(d+1)/2;
		sum=inv-sum;
		ll vv=sqrt(1+8*sum);
		int l1=mm-(vv-1)/2-1;

		cout<<"! "<<l1<<" "<<mm<<" "<<r1<<endl;
		cout.flush();
	}
	
	return 0;
}