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
	int i,j;
	int t,n,m;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		string ans="";
		ans+=s[0];
		for(i=1;i<s.size()-1;i+=2){
			ans+=s[i];
		}
		ans+=s[s.size()-1];
		cout<<ans<<endl;
	}
	return 0;
}