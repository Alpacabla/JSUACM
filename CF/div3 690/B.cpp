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
	string s1="2020";
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		bool ans=false;
		int k1=0,k2=0;
		for(int i=0;i<4;i++){
			if(s[i]==s1[i]) k1=i+1;
			else break;
		}
		for(int i=0;i<4;i++){
			if(s[n-i-1]==s1[4-i-1]) k2=i+1;
			else break;
		}
		if(k1+k2>=4) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}