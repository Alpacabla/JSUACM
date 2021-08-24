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
	ll a=1;
	vector<string> ss;
	auto getnum =  [] (ll aa) -> string{
		string s="";
		while(aa){
			s+=('0'+aa%10);
			aa/=10;
		}
		reverse(s.begin(),s.end());
		return s;
	};
	for(int i=1;a<=1e18;i++){
		ss.push_back(getnum(a));
		a*=2;
	}
	ss.push_back(getnum(a));
	//a*=2;
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int ans=int_inf;
		for(auto a:ss){
			int j=0;
			for(int i=0;i<s.size()&&j<a.size();i++){
				if(s[i]==a[j]){
					j++;
				}
			}
			ans=min(ans,(int)((int)s.size()+a.size()-2*j));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}