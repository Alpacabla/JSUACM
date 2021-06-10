// Problem: G. Gift Set
// Contest: Codeforces - Codeforces Round #725 (Div. 3)
// URL: https://codeforces.com/contest/1538/problem/G
// Memory Limit: 256 MB
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
int jjudge(int nn,int n,ll x,ll y,ll a,ll b)
{
	ll sum1=n*a+((nn-n)*b);
	ll sum2=n*b+((nn-n)*a);
	int res;
	if(sum1<=x&&sum2<=y) res=1;
	else{
		if(sum1>x){
			res=3;
		}else{
			res=2;
		}
	}
	return res;//sum1<=x&&sum2<=y;
}
bool judge(int n,ll x,ll y,ll a,ll b)
{
	ll l=0,r=n;
	ll res=-1;
	while(l<=r){
		int mid=(l+r)>>1;
		// if(x==8&&n==5){
			// cout<<endl;
			// cout<<mid<<endl;
		// }
		int res=jjudge(n,mid,x,y,a,b);
		if(res==1){
			res=mid;
			return true;
			//r=mid-1;
		}else{
			if(res==2){
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
	}
	return false;
}
ll solve(ll x,ll y,ll a,ll b)
{
	if(x<y) swap(x,y);
	if(a<b) swap(a,b);
	int l=1,r=1e9;
	ll res=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(judge(mid,x,y,a,b)){
			res=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
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
		int x,y,a,b;
		cin>>x>>y>>a>>b;
		cout<<solve(x,y,a,b)<<endl;
	}
	return 0;
}