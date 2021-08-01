// Problem: B. Gregor and the Pawn Game
// Contest: Codeforces - Codeforces Round #736 (Div. 2)
// URL: https://codeforces.com/contest/1549/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
		int n;
		cin>>n;
		string s1,s2;
		cin>>s1>>s2;
		string ss1=s1,ss2=s2;
		s1="0"+s1;
		s2="0"+s2;
		int ans=0;
		int cnt=0;
		for(int i=1;i<s1.size();i++){
			if(s2[i]=='1'){
				if(s1[i-1]=='1'){
					cnt++;
					s1[i-1]='0';
				}else{
					if(s1[i]=='0'){
						cnt++;
					}else{
						if(i+1<s1.size()&&s1[i+1]=='1'){
							cnt++;
							s1[i+1]='0';
						}
					}
				}
			}
		}
		ans=cnt;
		s1=ss1+"0";
		s2=ss2+"0";
		cnt=0;
		for(int i=s1.size()-2;i>=0;i--){
			if(s2[i]=='1'){
				if(s1[i+1]=='1'){
					cnt++;
					s1[i+1]='0';
				}else{
					if(s1[i]=='0'){
						cnt++;
					}else{
						if(i-1>=0&&s1[i-1]=='1'){
							cnt++;
							s1[i-1]='0';
						}
					}
				}
			}
		}
		ans=max(ans,cnt);
		cout<<ans<<endl;
	}
	return 0;
}