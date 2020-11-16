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
	int q;
	cin>>q;
	while(q--){
		string s;
		int n;
		cin>>n>>s;
		int cnt=0;
		vector<int> c1(0),c0(0);
		for(i=0;i<n;i++){
			if(i&&s[i]==s[i-1]){
				cnt++;
			}else{
				if(cnt>=2){
					if(s[i-1]=='1') c1.push_back(cnt);
					else c0.push_back(cnt);
				}
				cnt=1;
			}
		}
		if(cnt>=2){
			if(s[i-1]=='1') c1.push_back(cnt);
			else c0.push_back(cnt);
		}
		vector<int>::iterator a,b;
		int ans=int_inf;
		if(c1.size()!=0) a=c1.begin(),b=c1.end(),ans=0;
		for(;a!=b;a++){
			ans+=(*a)-1;
		}
		int t=int_inf;
		if(c0.size()!=0) a=c0.begin(),b=c0.end(),t=0;
		for(;a!=b;a++){
			t+=(*a)-1;
		}
		int out;
		if(t==int_inf) out=ans;
		if(ans==int_inf) out=t;
		if(t!=int_inf&&ans!=int_inf) out=max(ans,t);
		if(c1.size()==0&&c0.size()==0) out=0;
		cout<<out<<endl;
	}
	return 0;
}