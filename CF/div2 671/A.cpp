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
		int n;
		cin>>n;
		string s;
		cin>>s;
		int cnt1,cnt2;
		cnt1=cnt2=0;
		for(i=0;i<s.size();i+=2) cnt1+=(s[i]-'0')%2;
		for(i=1;i<s.size();i+=2) cnt2+=(((s[i]-'0')%2)==0);
		if(s.size()%2==1){
			if(cnt1){
				cout<<1<<endl;
			}else cout<<2<<endl;
		}else{
			if(cnt2){
				cout<<2<<endl;
			}else cout<<1<<endl;
		}

	}
	return 0;
}
