// Problem: C. Make Them Equal
// Contest: Codeforces - Codeforces Round #747 (Div. 2)
// URL: https://codeforces.com/contest/1594/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
		char ch;
		cin>>n>>ch;
		string s;
		cin>>s;
		s=" "+s;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt+=(s[i]==ch);
		}
		if(cnt==n){
			cout<<0<<endl;
			continue;
		}
		int ans=-1;
		for(int i=1;i<=n;i++){
			ans=i;
			for(int j=i;j<=n;j+=i){
				if(s[j]!=ch){
					ans=-1;
				}
			}
			if(ans!=-1){
				break;
			}
		}
		if(ans==-1){
			cout<<2<<endl;
			cout<<n<<" "<<n-1<<endl;
		}else{
			cout<<1<<endl;
			cout<<ans<<endl;
		}
	}
	return 0;
}