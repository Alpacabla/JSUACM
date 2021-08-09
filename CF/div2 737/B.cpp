// Problem: B. Moamen and k-subarrays
// Contest: Codeforces - Codeforces Round #737 (Div. 2)
// URL: https://codeforces.com/contest/1557/problem/B
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,kk;
		cin>>n>>kk;
		vector<int> a(n+1),b(n+1),k(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		sort(b.begin()+1,b.end());
		for(int i=1;i<=n;i++){
			k[i]=(int)(lower_bound(b.begin()+1,b.end(),a[i])-b.begin());
		}
		int i=1;
		int cnt=0;
		while(i<=n){
			//cout<<i<<endl;
			if(i==n){
				cnt++;
				break;
			}
			if(k[i]==k[i+1]-1){
				while(i<n&&k[i]==k[i+1]-1){
					i++;
				}
			}
			i++;
			cnt++;
		}
		cout<<(cnt>kk?"No":"Yes")<<endl;
	}
	return 0;
}