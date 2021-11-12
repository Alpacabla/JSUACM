// Problem: C. Dominant Character
// Contest: Codeforces - Codeforces Round #754 (Div. 2)
// URL: https://codeforces.com/contest/1605/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
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
	string ss[5]={
		"aa","aba","aca","accabba","abbacca"
	};
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string s;
		cin>>s;
		int ans=-1;
		for(int i=0;i<5;i++){
			if(s.find(ss[i])!=-1){
				ans=ss[i].size();
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}