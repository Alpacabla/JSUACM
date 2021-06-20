// Problem: D. PriceFixed
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.com/contest/1539/problem/D
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
struct node{
	ll a,b;
	bool operator < (const node aa) const{
		return b<aa.b;
	}
};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	
	vector<node> a(n+1);
	
	ll sum=0;
	for(int i=1;i<=n;i++) cin>>a[i].a>>a[i].b;
	for(int i=1;i<=n;i++) sum+=a[i].a;
	
	sort(a.begin()+1,a.end());
	ll res=0;
	ll now=0;
	int l=1,r=n;
	while(l<=r){
		while(r>=l&&now<a[l].b){
			if(now+a[r].a>a[l].b){
				a[r].a-=a[l].b-now;
				now=a[l].b;
			}else{
				now+=a[r].a;
				r--;
			}
		}
		if(l>r){
			break;
		}
		res+=a[l].a;
		now+=a[l].a;
		l++;
	}
	cout<<sum*2-res<<endl;
	
	return 0;
}