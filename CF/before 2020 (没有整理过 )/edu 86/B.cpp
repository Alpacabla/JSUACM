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
		string s;
		cin>>s;
		int cnt1,cnt2;
		cnt1=cnt2=0;
		for(i=0;i<s.size();i++){
			if(s[i]=='0') cnt1++;
			else cnt2++;
		}
		if(cnt1==s.size()||cnt2==s.size()){
			cout<<s<<endl;
		}else{
			int max1=s.size()*2-s.size();
			for(i=0;i<max1;i++){
				cout<<"01";
			}
			cout<<endl;
		}
	}
	return 0;
}