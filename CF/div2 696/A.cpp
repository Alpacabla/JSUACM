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
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		string ans="";
		cin>>s;
		bool flag1,falg2;
		char last='0';
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				if(last!='1') ans+='1',last='1';
				else ans+='0',last='0';
			}else{
				if(last!='2') ans+='1',last='2';
				else ans+='0',last='1';
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}