// Problem: C. Compressed Bracket Sequence
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
const int int_inf=0x3f3f3f3f;
const ll ll_inf=0x3f3f3f3f3f3f3f3f;
const int max_n=1e5+5;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(i%2){
			ll v=a[i];
			ll l=0;
			
			bool flag=false;
			for(int j=i+1;j<=n;j++){
				if(j%2==0){
					l-=a[j];
					if(l>0){
						continue;
					}
					if(v+l>=0){
						ans+=flag;
						v+=l;
						ans+=-l;
						l=0;
						flag=true;
					}else{
						ans+=flag;
						ans+=v;
						break;
					}
				}else{
					l+=a[j];
				}
			}
		}else{
			
		}
	}
	cout<<ans<<endl;
	return 0;
}