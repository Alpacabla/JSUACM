// Problem: B. Make it Divisible by 25
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.com/contest/1593/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
using namespace std;
#define endl '\n'
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
	vector<string> v;
	v.push_back("50");
	v.push_back("25");
	v.push_back("00");
	v.push_back("75");
	while(t--){
		string s;
		cin>>s;
		int ans=int_inf;
		for(int i=0;i<4;i++){
			int cnt=1;
			for(int j=s.size()-1;j>=0;j--){
				if(s[j]==v[i][cnt]){
					cnt--;
				}
				if(cnt==-1){
					ans=min(ans,int(s.size()-j)-2);
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}