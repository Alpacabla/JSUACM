// Problem: C. Rings
// Contest: Codeforces - Codeforces Round #741 (Div. 2)
// URL: https://codeforces.com/contest/1562/problem/C
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
		string s;
		cin>>n>>s;
		int k=-1;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				k=i+1;
			}
		}
		int len=s.size();
		if(k==-1){
			
			cout<<1<<" "<<len-1<<" "<<2<<" "<<len<<endl;
		}else{
			if(k>len/2){
				cout<<1<<" "<<k<<" "<<1<<" "<<k-1<<endl;
			}else{
				cout<<k<<" "<<len<<" "<<k+1<<" "<<len<<endl;
			}
		}
	}
	return 0;
}