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
	list<char> lis;
	string s1,s2;
	cin>>s1>>s2;
	list<char>::iterator p=lis.begin();
	for(int i=0;i<s1.size();i++){
		lis.insert(p,s1[i]);
		if(s2[i]=='L'){
			p--;
		}
	}
	for(p=lis.begin();p!=lis.end();p++){
		cout<<*p;
	}
	cout<<endl;
	return 0;
}