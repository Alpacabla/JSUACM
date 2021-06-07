// Problem: B. Prinzessin der Verurteilung
// Contest: Codeforces - Codeforces Round #724 (Div. 2)
// URL: https://codeforces.com/contest/1536/problem/B
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
	string a[3]={"a","aa","aaa"};
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		bool flag=true;
		int i=0;
		string ans;
		
		
		for(char i='a';i<='z'&&flag;i++){
			ans=i;	
			if(s.find(ans)==s.npos){
				flag=false;
			}
		}
		for(char i='a';i<='z'&&flag;i++){
			for(char j='a';j<='z'&&flag;j++){
				ans=i;
				ans+=j;
				if(s.find(ans)==s.npos){
					flag=false;
				}
			}
		}
		for(char i='a';i<='z'&&flag;i++){
			for(char j='a';j<='z'&&flag;j++){
				for(char k='a';k<='z'&&flag;k++){
					ans=i;
					ans+=j;
					ans+=k;
					if(s.find(ans)==s.npos){
						flag=false;
					}
					
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}