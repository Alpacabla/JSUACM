// Problem: H. Hopping Around the Array
// Contest: Codeforces - Deltix Round, Spring 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1523/problem/H
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
	// string s="1";
	// for(int i=1;i<1e3;i++){
		// s+='0';
	// }
	// cout<<s<<endl;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string a;
		cin>>a;
		a=" "+a+" ";
		for(int i=0;i<m;i++){
			vector<bool> vis(n+2);
			bool flag=true;
			for(int j=1;j<=n;j++){
				if(a[j]=='0'&&(((a[j+1]=='1')+(a[j-1]=='1'))==1)){
					vis[j]=true;;
					flag=false;
				}
			}
			for(int j=1;j<=n;j++){
				if(vis[j]) a[j]='1';
			}
			if(flag) {
				break;
			}
		}
		
		string s="";
		for(int j=1;j<=n;j++) s+=a[j];
		cout<<s<<'\n';
	}
	return 0;
}