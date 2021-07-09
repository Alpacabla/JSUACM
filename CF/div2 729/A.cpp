// Problem: A. Odd Set
// Contest: Codeforces - Codeforces Round #729 (Div. 2)
// URL: https://codeforces.com/contest/1542/problem/A
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
		n*=2;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i]%2==1){
				cnt1++;
			}else{
				cnt2++;
			}
		}
		if(cnt2!=cnt1) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}