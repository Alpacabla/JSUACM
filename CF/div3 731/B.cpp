// Problem: B. Alphabetical Strings
// Contest: Codeforces - Codeforces Round #731 (Div. 3)
// URL: https://codeforces.com/contest/1547/problem/B
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

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
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int now=-1;
		int l,r;
		l=r=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='a'){
				now=i;
				break;
			}
		}
		bool flag=false;
		if(now!=-1){
			l=r=now;
			l--;
			r++;
			char last=s[now];
			bool endend=false;
			while(1){
				if(l>=0){
					if(s[l]==last+1){
						last=s[l];
						l--;
						continue;
					}
				}
				if(r<s.size()){
					if(s[r]==last+1){
						last=s[r];
						r++;
						continue;
					}
				}
				if(l<0&&r>=s.size()){
					break;
				}
				endend=true;
				break;
			}
			flag=!endend;
		}
		cout<<(flag?"Yes":"No")<<endl;
	}
	return 0;
}