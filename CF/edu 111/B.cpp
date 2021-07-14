// Problem: B. Maximum Cost Deletion
// Contest: Codeforces - Educational Codeforces Round 111 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1550/problem/B
// Memory Limit: 256 MB
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
		int n,a,b;
		string s;
		cin>>n>>a>>b;
		cin>>s;
		int cnt1=0,cnt2=0;
		for(int i=0;i<n;i++){
			bool flag=true;
			while(i<n&&s[i]=='0'){
				i++;
				flag=false;
			}
			cnt1+=!flag;
			
			flag=true;
			while(i<n&&s[i]=='1'){
				i++;
				flag=false;
			}
			cnt2+=!flag;
			if(!flag){
				i--;
			}
		}
		if(b>0){
			cout<<a*n+b*n<<endl;
		}else{
			cout<<a*n+b*min(cnt1+1,cnt2+1)<<endl;
		}
	}
	return 0;
}