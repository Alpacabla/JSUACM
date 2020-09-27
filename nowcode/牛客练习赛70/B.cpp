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
stack<int> ind[150];
bool check()
{	
	string s="puleyaknoi";
	for(int i=0;i<s.size();i++){
		if(ind[s[i]].size()==0){
			return false;
		}
		while(i&&ind[s[i]].size()&&ind[s[i]].top()<ind[s[i-1]].top()){
			ind[s[i]].pop();
		}
		if(ind[s[i]].size()==0) return false;
	}
	for(int i=1;i<s.size();i++){
		if(ind[s[i]].top()<ind[s[i-1]].top()) return false;
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
		for(i=0;i<150;i++){
			while(ind[i].size()) ind[i].pop();
		}
		int l=0,r=0;
		int min1=int_inf;
		while(1){
			while(r<s.size()&&!check()){
				ind[s[r]].push(r);
				r++;
			}
			// if(r==r.size()) r--;
			if(!check()) break;
			min1=min(min1,ind['i'].top()-ind['p'].top()+1);
			//cout<<min1<<endl;
			while(l<r&&check()){
				if(ind[s[l]].size()&&(ind[s[l]].top()==l||ind[s[l]].top()<l)){
					ind[s[l]].pop();
					//cout<<'u'<<endl;
				}
				l++;
				if(check()){
					// cout<<'y'<<endl;
					min1=min(min1,ind['i'].top()-ind['p'].top()+1);
				}
			}
			if(r==s.size()&&!check()) break;
		}
		if(min1!=int_inf) cout<<min1<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
