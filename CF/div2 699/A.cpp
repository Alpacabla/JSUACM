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
		int x,y;
		string s;
		cin>>x>>y;
		cin>>s;
		int cnt[4]={0};
		char ss[5]="UDRL";
		for(int i=0;i<s.size();i++){
			for(int j=0;j<4;j++){
				if(s[i]==ss[j]){
					cnt[j]++;
					break;
				}
			}
		}
		bool flag=true;
		if(x>0) flag=cnt[2]>=x;
		else flag=cnt[3]>=-x;
		if(flag){
			if(y>0) flag=cnt[0]>=y;
			else flag=cnt[1]>=-y;
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}