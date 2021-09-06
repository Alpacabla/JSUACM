// Problem: A. Forgetting Things
// Contest: Codeforces - Codeforces Round #596 (Div. 2, based on Technocup 2020 Elimination Round 2)
// URL: https://codeforces.com/contest/1247/problem/A
// Memory Limit: 512 MB
// Time Limit: 2000 ms
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
	int a,b;
	cin>>a>>b;
	if(a==b){
		cout<<a<<0<<" "<<b<<1<<endl;
	}else{
		if(a+1==b){
			cout<<a<<9<<" "<<b<<0<<endl;
		}else{
			if(a==9&&b==1){
				cout<<a<<" "<<10<<endl;
			}else{
				cout<<-1<<endl;
			}
		}
	}
	return 0;
}