// Problem: B. MEXor Mixup
// Contest: Codeforces - Codeforces Round #742 (Div. 2)
// URL: https://codeforces.com/contest/1567/problem/B
// Memory Limit: 256 MB
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
	vector<int> x(3e5+5);
	for(int i=1;i<=3e5;i++){
		x[i]=x[i-1]^i;
	}
	int t;
	cin>>t;
	while(t--){
		int a,b;
		cin>>a>>b;
		if(b==x[a-1]){
			cout<<a<<endl;
		}else{
			if(b==x[a]){
				cout<<a+2<<endl;
			}else{
				cout<<a+1<<endl;
			}
		}
	}
	return 0;
}