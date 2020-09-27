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
int cnt[max_n];
bool check()
{	
	string s="puleyaknoi";
	for(int i=0;i<s.size();i++){
		if(!cnt[s[i]]) return false;
	}
	return true;
}
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
		memset(cnt,0,sizeof(cnt));
		int l=0,r=0;
		int min1=int_inf;
		while(1){
			while(r<s.size()&&!check()){
				cnt[s[r++]]++;
			}
			if(!check()) break;
			min1=min(min1,r-l);
			while(l<r&&check()){
				cnt[s[l++]]--;
				if(check()){
					min1=min(min1,r-l);
				}
			}
			if(r==s.size()&&!check()) break;
		}
		if(min1!=int_inf) cout<<min1<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
