// Problem: C. Unstable String
// Contest: Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1535/problem/C
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
		string s;
		cin>>s;
		s="?"+s;
		int last=0;
		ll ans=0;
		int now=1;
		bool vis=false;
		int llast=0;
		bool ju=false;
		for(int i=1;i<s.size();i++){
			if(s[i]=='?'){
				last=!last;
				if(!ju){
					ju=true;
					llast=i;
				}
			}else{
				if(!vis){
					last=s[i]-'0';
					vis=true;
				}else{
					if(last!=!(s[i]-'0')){
						now=i;
						if(ju==true){
							now=llast;
						}
					}
					last=s[i]-'0';
				}
				ju=false;
				llast=i;
			}
			int len=(i-now+1);
			ans=ans+len;
		}
		cout<<ans<<endl;
	}
	return 0;
}