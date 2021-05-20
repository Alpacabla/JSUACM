// Problem: B2. Palindrome Game (hard version)
// Contest: Codeforces - Codeforces Round #721 (Div. 2)
// URL: https://codeforces.com/contest/1527/problem/B2
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
		string s;
		cin>>s;
		int cnt=0;
		int k=0;
		for(int i=0;i<n/2;i++){
			if(s[i]!=s[n-i-1]){
				cnt++;
			}
		}
		for(int i=0;i<n;i++){
			k+=s[i]=='0';
		}
		int mid=n/2;
		if(cnt==0){
			if(k%2==0||k==1) cout<<"BOB"<<endl;
			else cout<<"ALICE"<<endl;
			continue;
		}
		
		if(n%2==1&&s[mid]=='0'){
			if(cnt==1&&k==2){
				cout<<"DRAW"<<endl;
			}else{
				cout<<"ALICE"<<endl;
			}
		}else{
			cout<<"ALICE"<<endl;
		}
	}
	return 0;
}