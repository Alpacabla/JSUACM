// Problem: B. PIN Codes
// Contest: Codeforces - Codeforces Round #603 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1263/B
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
		vector<string> a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		auto judge=[&n](string &s,vector<string> &ss) -> bool{
			for(int i=1;i<=n;i++){
				if(ss[i]==s) return true;
			}
			return false;
		};
		for(int i=1;i<=n;i++){
			bool flag=false;
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]){
					flag=true;
					break;
				}
			}
			if(flag){
				ans++;
				string t=a[i];
				for(int k=0;k<4&&flag;k++){
					for(int l='0';l<='9'&&flag;l++){
						t[k]=l;
						if(judge(t,a)){
							t=a[i];
							continue;
						}
						a[i]=t;
						flag=false;
					}
				}
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++) cout<<a[i]<<endl;
		cout<<endl;
	}
	return 0;
}