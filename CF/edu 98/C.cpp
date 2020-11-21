/*
link: 
tags: 
*/
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
		int ans=0;
		int a=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='('){
				a++;
			}else{
				if(s[i]==')'){
					if(a){
						a--;
						ans++;
					}
				}
				
			}
			//cout<<a<<endl;
		}
		a=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='['){
				a++;
			}else{
				if(s[i]==']'){
					if(a){
						a--;
						ans++;
					}
				}
				
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}