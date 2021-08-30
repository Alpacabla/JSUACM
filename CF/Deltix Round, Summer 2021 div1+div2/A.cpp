// Problem: A. A Variety of Operations
// Contest: Codeforces - Deltix Round, Summer 2021 (open for everyone, rated, Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1556/problem/A
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define to_l(a) ((a)<<1)
#define to_r(a) ((a)<<1|1)
#define lowbit(a) ((a)&(-a))
#define endl '\n'
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
		int a,b;
		cin>>a>>b;
		if(!a&&!b) cout<<0<<endl;
		else{
			if(a==b){
				cout<<1<<endl;
				continue;
			}
			if((abs(a-b)%2)==1){
				cout<<-1<<endl;
			}else{
				cout<<2<<endl;
			}
		}
	}
	return 0;
}