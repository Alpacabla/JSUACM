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
		int last=-5;
		int max1=-1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				if(i-last>1){
					last=i;
				}else{
					//max1=i-1;
					break;
				}
			}
			max1=i;
		}
		last=s.size()+5;
		int min1=int_inf;
		for(int i=s.size()-1;i>=0;i--){
			if(s[i]=='0'){
				if(last-i>1){
					last=i;
				}else{
					//max1=i-1;
					break;
				}
			}
			min1=i;
		}
		if(min1<=max1) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}