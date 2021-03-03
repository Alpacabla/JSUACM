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
int cnt1[5][200],cnt2[5][200];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,j;
	int n;
	string t="SLM";
	cin>>n;
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		cnt1[s.size()][s[s.size()-1]]++;
	}
	for(int i=1;i<=n;i++){
		string s;
		cin>>s;
		cnt2[s.size()][s[s.size()-1]]++;
	}
	int ans=0;
	for(int i=1;i<=4;i++){
		for(int j=0;j<3;j++){
			if(cnt1[i][t[j]]>cnt2[i][t[j]]){
				ans+=cnt1[i][t[j]]-cnt2[i][t[j]];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}