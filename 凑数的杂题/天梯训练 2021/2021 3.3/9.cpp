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
	string s;
	while(getline(cin,s)){
		stringstream ss(s);
		//string t;
		string out="";
		bool flag=false;
		while(ss>>s){
			if(flag) out=" ";
			else out="";
			if(islower(s[0])) s[0]=s[0]-32;
			out+=s[0];
			for(int i=1;i<s.size();i++){
				if(isalpha(s[i-1])&&isdigit(s[i])){
					out+='_';
				}
				if(isalpha(s[i])&&isdigit(s[i-1])){
					out+='_';
				}
				out+=s[i];
			}
			cout<<out;
			flag=true;
		}
		cout<<endl;
	}
	return 0;
}