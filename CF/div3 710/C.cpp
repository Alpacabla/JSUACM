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
		string s1,s2;
		cin>>s1>>s2;
		int ans=s1.size()+s2.size();
		for(int i=1;i<=s1.size();i++){
			for(int y=0;y+i<=s1.size();y++){
				string t="";
				for(int j=y,len=0;len<i;j++,len++){
					t+=s1[y+len];
				}
				for(int k=0;k<s2.size()&&k+t.size()-1<s2.size();k++){
					int l=0,p=0;
					for(;t[l]==s2[k+p]&&l<t.size();l++,p++);
					if(l==t.size()) ans=min(ans,(int)(s2.size()+s1.size()-2*i));
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}