// Problem: D. Blue-Red Permutation
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/contest/1607/problem/D
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
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n+1);
		for(int i=1;i<=n;i++) cin>>a[i];
		string s;
		cin>>s;
		vector<int> aa,bb;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='B') aa.push_back(a[i]);
			else bb.push_back(a[i]);
		}
		sort(aa.begin(),aa.end());
		sort(bb.begin(),bb.end(),greater<int>());
		bool flag=true;
		int l=1;
		for(int i=0;i<aa.size();i++){
			//cout<<aa[i]<<" ";
			if(aa[i]>=l){
				l++;
			}else{
				flag=false;
			}
		}
		//cout<<endl;
		l=n;
		for(int i=0;i<bb.size();i++){
			//cout<<bb[i]<<" ";
			if(bb[i]<=l){
				l--;
			}else{
				flag=false;
			}
		}
		cout<<(flag?"YES":"NO")<<endl;
		
	}
	return 0;
}